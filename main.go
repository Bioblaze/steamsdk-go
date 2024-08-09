package main

// steamworks.go

/*
#cgo LDFLAGS: -Lbuild/windows -lsteam_api -lsteamworks_wrapper
#cgo CFLAGS: -I./steamworks_sdk/public -I./cpp -fno-exceptions
#cgo CXXFLAGS: -std=c++11
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h> // Add this to include standard library for free
#include "bindings.cpp"

*/
import "C"
import (
	"fmt"
	"unsafe"
)

func InitFlat() (C.ESteamAPIInitResult, string) {
    var errMsg [C.k_cchMaxSteamErrMsg]C.char
    result := C.SteamSDKAPI_InitFlat((*C.SteamErrMsg)(unsafe.Pointer(&errMsg[0])))
    return result, C.GoString(&errMsg[0])
}

func Shutdown() {
    C.SteamSDKAPI_Shutdown()
}

func RestartAppIfNecessary(unOwnAppID uint32) bool {
    return bool(C.SteamSDKAPI_RestartAppIfNecessary(C.uint32_t(unOwnAppID)))
}

func ReleaseCurrentThreadMemory() {
    C.SteamSDKAPI_ReleaseCurrentThreadMemory()
}

func WriteMiniDump(uStructuredExceptionCode uint32, pvExceptionInfo unsafe.Pointer, uBuildID uint32) {
    C.SteamSDKAPI_WriteMiniDump(C.uint32_t(uStructuredExceptionCode), pvExceptionInfo, C.uint32_t(uBuildID))
}

func SetMiniDumpComment(pchMsg string) {
    cStr := C.CString(pchMsg)
    defer C.free(unsafe.Pointer(cStr))
    C.SteamSDKAPI_SetMiniDumpComment(cStr)
}

func IsSteamRunning() bool {
    return bool(C.SteamSDKAPI_IsSteamRunning())
}
func main() {
    result, errMsg := InitFlat()
    if result != C.k_ESteamAPIInitResult_OK {
        fmt.Println("Steam API initialization failed:", errMsg)
    } else {
        fmt.Println("Steam API initialized successfully")
    }

    fmt.Println("Is Steam Running:", IsSteamRunning())

    Shutdown()
}