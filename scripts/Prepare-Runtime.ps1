[CmdletBinding()]
param([ValidateSet('Debug','Release')][string]$Configuration = 'Debug', [string]$Source)
$ErrorActionPreference = 'Stop'
$root = Split-Path $PSScriptRoot -Parent
if (!$Source) {
    $settings = Join-Path $root '.local\settings.json'
    if (Test-Path $settings) { $Source = (Get-Content $settings -Raw | ConvertFrom-Json).assetSource }
}
if (!$Source) { $Source = Join-Path $root 'runtime' }
& (Join-Path $PSScriptRoot 'Check-Assets.ps1') -Source $Source
$exe = Join-Path $root "$Configuration\DreeRally.exe"
if (!(Test-Path $exe)) { throw "Build $Configuration first." }
$runtime = Join-Path $root 'runtime'
New-Item -ItemType Directory -Path $runtime -Force | Out-Null
# Copy only runtime data. Never copy or modify original saves/configuration.
$names = @('ENGINE.BPA','IBFILES.BPA','MENU.BPA','MUSICS.BPA','TR0.BPA','TR1.BPA','TR2.BPA','TR3.BPA','TR4.BPA','TR5.BPA','TR6.BPA','TR7.BPA','TR8.BPA','TR9.BPA','ENDANI.haf','ENDANI0.HAF','SANIM.haf','SDL.dll','fmod.dll','msvcr71.dll')
if ((Resolve-Path $Source).Path -ne (Resolve-Path $runtime).Path) {
    foreach ($name in $names) {
        $file = Join-Path $Source $name
        if (Test-Path -LiteralPath $file) { Copy-Item -LiteralPath $file -Destination $runtime }
    }
}
Copy-Item -LiteralPath $exe -Destination $runtime -Force
$pdb = Join-Path $root "$Configuration\DreeRally.pdb"
if (Test-Path $pdb) { Copy-Item -LiteralPath $pdb -Destination $runtime -Force }
foreach ($folder in @('lang','mods')) { Copy-Item -LiteralPath (Join-Path $root $folder) -Destination $runtime -Recurse -Force }
Write-Host "Runtime ready: $runtime"
