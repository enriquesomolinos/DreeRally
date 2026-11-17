[CmdletBinding()]
param()
$ErrorActionPreference = 'Stop'
$root = Split-Path $PSScriptRoot -Parent
$testDir = Join-Path $root '.local\tests'
New-Item -ItemType Directory -Path $testDir -Force | Out-Null
$source = Get-Content (Join-Path $root 'dr.c') -Raw
$names = @('drawToBlackScreen', 'setCircuitPalette_4B4020', 'setCircuitPaletteBis_4B4020', 'setCircuitPaletteTransitionToBlack_4B4020', 'setCircuitPaletteTransitionToOriginal_4B4020', 'showSmoke_40F070')
$functions = foreach ($name in $names) {
    $match = [regex]::Match($source, '(?ms)^int\s+' + $name + '\([^)]*\)\s*\{.*?(?=^//-----)')
    if (!$match.Success) { throw "Cannot find palette function: $name" }
    $match.Value
}
$functions -join "`n" | Set-Content (Join-Path $testDir 'race-palette-functions.inc') -Encoding ASCII
$vswhere = Join-Path ${env:ProgramFiles(x86)} 'Microsoft Visual Studio\Installer\vswhere.exe'
$vs = @(& $vswhere -latest -products '*' -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath)[0]
if (!$vs) { throw 'MSVC C++ build tools not found.' }
$vcvars = Join-Path $vs 'VC\Auxiliary\Build\vcvars32.bat'
Push-Location $root
try {
    # vcvars32.bat escribe en stderr aunque funcione; se redirige dentro de cmd para que
    # PowerShell no lo tome como error y aborte el script.
    $compileLog = Join-Path $testDir 'compile.log'
    $command = 'call "' + $vcvars + '" >nul 2>&1 && cl /nologo /W3 /I.local\tests /Fe:.local\tests\race-palette-test.exe /Fo:.local\tests\race-palette-test.obj tests\race_palette_test.c > "' + $compileLog + '" 2>&1'
    & cmd.exe /c $command | Out-Null
    if ($LASTEXITCODE -ne 0) { Get-Content $compileLog; throw 'Palette test compilation failed.' }
    & (Join-Path $testDir 'race-palette-test.exe')
    if ($LASTEXITCODE -ne 0) { throw 'Palette regression tests failed.' }
} finally { Pop-Location }
