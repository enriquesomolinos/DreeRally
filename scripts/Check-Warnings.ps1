# Compila con advertencias activas y bloquea las que en este codigo han provocado
# fallos reales. El resto del ruido heredado del decompilado se compara contra una
# linea base: sirve para no dejar entrar advertencias nuevas sin arreglar las viejas.
#
#   scripts\Check-Warnings.ps1              -> compara contra la linea base
#   scripts\Check-Warnings.ps1 -UpdateBaseline  -> reescribe la linea base
[CmdletBinding()]
param([ValidateSet('Debug','Release')][string]$Configuration = 'Debug', [switch]$UpdateBaseline)
$ErrorActionPreference = 'Stop'
$root = Split-Path $PSScriptRoot -Parent

# Codigos que rompen el programa en silencio y no se toleran nunca.
# C4013 es el que dejo a ceil() devolviendo basura desde eax y colgo la pantalla
# de seleccion de carrera: sin prototipo, el valor de retorno y los argumentos
# float/double se pasan mal.
$blocking = @{
    'C4013' = 'funcion sin prototipo (retorno y argumentos float se leen mal)'
    'C4700' = 'variable local usada sin inicializar'
    'C4715' = 'no todas las rutas devuelven un valor'
    'C4716' = 'la funcion debe devolver un valor'
    'C4739' = 'escritura fuera del almacenamiento de la variable'
    'C4293' = 'desplazamiento negativo o demasiado grande'
    'C4554' = 'precedencia de operadores sospechosa'
    'C4133' = 'tipos de puntero incompatibles'
    'C4113' = 'listas de parametros distintas en puntero a funcion'
    'C4022' = 'puntero que no coincide con el parametro'
    'C4047' = 'niveles de indireccion distintos'
    'C4028' = 'parametro distinto de la declaracion (float/double se leen corridos)'
}

$vswhere = Join-Path ${env:ProgramFiles(x86)} 'Microsoft Visual Studio\Installer\vswhere.exe'
if (!(Test-Path $vswhere)) { throw 'Install Visual Studio Build Tools with Desktop development with C++.' }
$vs = @(& $vswhere -latest -products '*' -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath)[0]
if (!$vs) { throw 'No MSVC x86/x64 toolchain found.' }
$vcvars = Join-Path $vs 'VC\Auxiliary\Build\vcvars32.bat'

$work = Join-Path $root '.local\warnings'
New-Item -ItemType Directory -Path $work -Force | Out-Null
$sources = (Select-String -Path (Join-Path $root 'DreeRally.vcxproj') -Pattern '<ClCompile Include="([^"]*)"' -AllMatches).Matches |
    ForEach-Object { $_.Groups[1].Value }

Push-Location $root
try {
    $defines = if ($Configuration -eq 'Debug') { '/D_DEBUG' } else { '/DNDEBUG' }
    # Rutas relativas a la raiz: /Fo no admite espacios sin comillas y la ruta del
    # repositorio los tiene. vcvars32.bat ademas escribe en stderr aunque funcione,
    # asi que se redirige todo dentro de cmd y PowerShell no lo toma como error.
    $objDir = '.local\warnings\'
    $output = '.local\warnings\cl-output.txt'
    $command = 'call "' + $vcvars + '" >nul 2>&1 && cl /nologo /c /W3 /D_CRT_SECURE_NO_WARNINGS /DWIN32 ' +
               $defines + ' /D_WINDOWS /Ilibincludes /Ilibs /Fo:' + $objDir + ' ' + ($sources -join ' ') +
               ' > ' + $output + ' 2>&1'
    & cmd.exe /c $command | Out-Null
    $global:LASTEXITCODE = 0
    # cmd escribe en la pagina de codigos OEM; leerlo como UTF-8 destroza los acentos.
    $oem = [System.Text.Encoding]::GetEncoding([System.Globalization.CultureInfo]::CurrentCulture.TextInfo.OEMCodePage)
    $raw = if (Test-Path $output) { [System.IO.File]::ReadAllLines((Resolve-Path $output), $oem) } else { @() }
    if (!$raw.Count) { throw "El compilador no produjo salida. Revisa $output" }
} finally { Pop-Location }

# Solo advertencias de archivos del proyecto; las de las cabeceras del SDK no son nuestras.
# La clave ignora el numero de linea: al insertar o quitar lineas en un archivo grande
# todas las advertencias posteriores se corren y aparecerian como nuevas sin serlo.
# Para no perder sensibilidad se compara el numero de apariciones de cada clave.
$counts = @{}
$total = 0
foreach ($line in $raw) {
    $text = [string]$line
    if ($text -notmatch 'warning (C\d+)') { continue }
    if ($text -match 'Windows Kits|Microsoft Visual Studio') { continue }
    $code = $matches[1]
    $normalised = ($text -replace '^\s+','' -replace '\s+$','' -replace '\(\d+(,\d+)?\)', '')
    $normalised = $normalised -replace '^.*[\/]([^\/]+\.c)', '$1'
    if (!$counts.ContainsKey($normalised)) { $counts[$normalised] = [pscustomobject]@{ Code = $code; Count = 0 } }
    $counts[$normalised].Count++
    $total++
}

# En scripts/ y no en .local/ para que la linea base viaje con el repositorio.
$baselineFile = Join-Path $PSScriptRoot 'warnings-baseline.txt'
if ($UpdateBaseline) {
    $counts.Keys | Sort-Object | ForEach-Object { "{0}`t{1}" -f $counts[$_].Count, $_ } |
        Set-Content $baselineFile -Encoding UTF8
    Write-Host "Linea base escrita: $baselineFile ($total advertencias, $($counts.Count) claves)"
    return
}

Write-Host "Advertencias en archivos del proyecto: $total"
foreach ($code in ($blocking.Keys | Sort-Object)) {
    $n = 0
    foreach ($key in $counts.Keys) { if ($counts[$key].Code -eq $code) { $n += $counts[$key].Count } }
    if ($n) { Write-Host ("  {0}  {1,4}  {2}" -f $code, $n, $blocking[$code]) }
}

$baseline = @{}
if (Test-Path $baselineFile) {
    foreach ($line in Get-Content $baselineFile) {
        $parts = $line -split "`t", 2
        if ($parts.Count -eq 2) { $baseline[$parts[1]] = [int]$parts[0] }
    }
}

$new = @()
foreach ($key in ($counts.Keys | Sort-Object)) {
    $was = if ($baseline.ContainsKey($key)) { $baseline[$key] } else { 0 }
    if ($counts[$key].Count -gt $was) { $new += [pscustomobject]@{ Key = $key; Code = $counts[$key].Code; Was = $was; Now = $counts[$key].Count } }
}
if (!$new.Count) { Write-Host 'Sin advertencias nuevas respecto de la linea base.'; return }

Write-Host ''
Write-Host "Advertencias NUEVAS ($($new.Count)):"
$new | ForEach-Object { Write-Host ("  [{0} -> {1}] {2}" -f $_.Was, $_.Now, $_.Key) }
$newBlocking = @($new | Where-Object { $blocking.ContainsKey($_.Code) })
if ($newBlocking.Count) { throw "$($newBlocking.Count) advertencia(s) nueva(s) de la lista bloqueante." }
