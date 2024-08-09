# Directories
$OUTPUT_DIR = "build\windows"

# Ensure output directory exists
if (-Not (Test-Path -Path $OUTPUT_DIR)) {
    New-Item -ItemType Directory -Force -Path $OUTPUT_DIR
}

# Set the CGO_LDFLAGS and CGO_CFLAGS environment variables to point to the output directory and include path
$Env:GOARCH = 'amd64'
$env:CGO_LDFLAGS = "-L$PWD\$OUTPUT_DIR -lsteamworks_wrapper"
$env:CGO_CFLAGS = "-I$PWD\cpp -I$PWD\steamworks_sdk\public"
$env:CGO_CXXFLAGS = "-std=c++11"

# Build the Go application
go build -o "$OUTPUT_DIR\steamworks_app.exe" main.go
Remove-Item Env:GOARCH

Write-Host "Go application built and copied to $OUTPUT_DIR"
