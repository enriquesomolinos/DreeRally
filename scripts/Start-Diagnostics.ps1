[CmdletBinding()]
param(
    [ValidateSet('Debug','Release')][string]$Configuration = 'Debug',
    [switch]$SkipBuild,
    [string[]]$GameArguments = @('-window')
)
$ErrorActionPreference = 'Stop'
$root = Split-Path $PSScriptRoot -Parent
$runtime = Join-Path $root 'runtime'
if (Get-Process DreeRally -ErrorAction SilentlyContinue) {
    throw 'Close the running game before starting a diagnostic session.'
}
if (!$SkipBuild) { & (Join-Path $PSScriptRoot 'Build.ps1') -Configuration $Configuration }
& (Join-Path $PSScriptRoot 'Prepare-Runtime.ps1') -Configuration $Configuration

# Official portable Sysinternals tool; no system-wide debugger registration.
$toolDir = Join-Path $root '.local\procdump'
$procdump = Join-Path $toolDir 'procdump.exe'
if (!(Test-Path -LiteralPath $procdump)) {
    New-Item -ItemType Directory -Path $toolDir -Force | Out-Null
    $archive = Join-Path $toolDir 'Procdump.zip'
    Invoke-WebRequest 'https://download.sysinternals.com/files/Procdump.zip' -OutFile $archive -UseBasicParsing
    Expand-Archive -LiteralPath $archive -DestinationPath $toolDir -Force
}
$signature = Get-AuthenticodeSignature -LiteralPath $procdump
if ($signature.Status -ne 'Valid' -or $signature.SignerCertificate.Subject -notmatch 'O=Microsoft Corporation') {
    throw 'ProcDump does not have a valid Microsoft signature.'
}
$session = Join-Path $runtime ('logs\diagnostic-' + (Get-Date -Format 'yyyyMMdd-HHmmss-fff'))
New-Item -ItemType Directory -Path $session -Force | Out-Null
# Keep the matching binary and symbols even if the next build replaces runtime/.
Copy-Item -LiteralPath (Join-Path $runtime 'DreeRally.exe') -Destination $session
$pdb = Join-Path $runtime 'DreeRally.pdb'
if (Test-Path -LiteralPath $pdb) { Copy-Item -LiteralPath $pdb -Destination $session }
@{
    started = (Get-Date).ToString('o')
    configuration = $Configuration
    arguments = $GameArguments
    executableSha256 = (Get-FileHash (Join-Path $runtime 'DreeRally.exe')).Hash
    revision = (& git -C $root rev-parse HEAD)
    changes = @(& git -C $root status --short)
} | ConvertTo-Json | Set-Content (Join-Path $session 'session.json') -Encoding UTF8
Write-Host "Diagnostics: $session"
Write-Host 'Session logs are in runtime/logs. An unhandled exception will also produce a full .dmp.'
Push-Location $runtime
try {
    & $procdump -accepteula -ma -e -x $session (Join-Path $runtime 'DreeRally.exe') @GameArguments 2>&1 |
        ForEach-Object { $_.ToString().Replace([string][char]0, '') } |
        Tee-Object -FilePath (Join-Path $session 'procdump.log')
    $monitorExit = $LASTEXITCODE
    "ProcDump exit code: $monitorExit" | Add-Content (Join-Path $session 'procdump.log')
    if (Get-ChildItem -LiteralPath $session -Filter '*.dmp') {
        Write-Host "Crash dump captured: $session"
    } elseif ($monitorExit -ne 0) {
        throw "ProcDump exited with code $monitorExit without a dump. See $session"
    }
} finally { Pop-Location }
