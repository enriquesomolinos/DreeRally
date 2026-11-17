[CmdletBinding()]
param([ValidateSet('Debug','Release')][string]$Configuration = 'Debug')
$ErrorActionPreference = 'Stop'
$root = Split-Path $PSScriptRoot -Parent
$vswhere = Join-Path ${env:ProgramFiles(x86)} 'Microsoft Visual Studio\Installer\vswhere.exe'
if (!(Test-Path $vswhere)) { throw 'Install Visual Studio Build Tools with Desktop development with C++.' }
$vs = & $vswhere -latest -products '*' -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath
if (!$vs) { throw 'No MSVC x86/x64 toolchain found. Install the C++ build tools.' }
$toolsVersion = (Get-Content (Join-Path $vs 'VC\Auxiliary\Build\Microsoft.VCToolsVersion.default.txt')).Trim()
$minor = [int]($toolsVersion.Split('.')[1])
$toolset = if ($minor -ge 30) { 'v143' } elseif ($minor -ge 20) { 'v142' } else { throw "Unsupported MSVC version: $toolsVersion" }
$msbuild = Join-Path $vs 'MSBuild\Current\Bin\MSBuild.exe'
Push-Location $root
try {
    & $msbuild DreeRally.vcxproj /nologo /m /v:minimal "/p:Configuration=$Configuration" /p:Platform=Win32 "/p:PlatformToolset=$toolset" /p:WindowsTargetPlatformVersion=10.0
    if ($LASTEXITCODE -ne 0) { throw "MSBuild failed ($LASTEXITCODE)." }
    Write-Host "Built: $root\$Configuration\DreeRally.exe"
} finally { Pop-Location }
