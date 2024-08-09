#ifndef STEAMWORKS_WRAPPER_H
#define STEAMWORKS_WRAPPER_H

// Ensure correct C++ standard is enforced
#if __cplusplus < 201103L
#error "This library requires C++11 or higher"
#endif

#include "steam/steam_api.h"

#ifdef _WIN32
    #ifdef STEAMWORKS_WRAPPER_EXPORTS
        #define STEAMWORKS_WRAPPER_API __declspec(dllexport)
    #else
        #define STEAMWORKS_WRAPPER_API __declspec(dllimport)
    #endif
#else
    #define STEAMWORKS_WRAPPER_API
#endif

extern "C" {
    STEAMWORKS_WRAPPER_API ESteamAPIInitResult SteamAPI_InitFlat(SteamErrMsg *pOutErrMsg);
    STEAMWORKS_WRAPPER_API void SteamAPI_Shutdown();
    STEAMWORKS_WRAPPER_API bool SteamAPI_RestartAppIfNecessary(uint32 unOwnAppID);
    STEAMWORKS_WRAPPER_API void SteamAPI_ReleaseCurrentThreadMemory();
    STEAMWORKS_WRAPPER_API void SteamAPI_WriteMiniDump(uint32 uStructuredExceptionCode, void* pvExceptionInfo, uint32 uBuildID);
    STEAMWORKS_WRAPPER_API void SteamAPI_SetMiniDumpComment(const char *pchMsg);
    STEAMWORKS_WRAPPER_API bool SteamAPI_IsSteamRunning();
}

#endif // STEAMWORKS_WRAPPER_H
