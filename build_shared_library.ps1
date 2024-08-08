# Directories
$SDK_DIR = "steamworks_sdk"
$CPP_FILE = "cpp\steamworks_wrapper.cpp"
$OUTPUT_DIR = "build\windows"
$ARCH = "win64" # Change this to "win32" if you are targeting a 32-bit system

# Ensure output directory exists
if (-Not (Test-Path -Path $OUTPUT_DIR)) {
    New-Item -ItemType Directory -Force -Path $OUTPUT_DIR
}

# Build the shared library
g++ -shared -o "$OUTPUT_DIR\steamworks_wrapper.dll" $CPP_FILE -I"$PWD\$SDK_DIR\public" -I"$PWD\cpp" -L"$PWD\$SDK_DIR\redistributable_bin\$ARCH" -l:steam_api64.dll

# Copy required files to output directory
Get-ChildItem "$SDK_DIR\redistributable_bin\$ARCH\*" -File | Copy-Item -Destination $OUTPUT_DIR -Force

Write-Host "Shared library built and copied to $OUTPUT_DIR"
