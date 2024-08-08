#ifndef STEAMWORKS_WRAPPER_H
#define STEAMWORKS_WRAPPER_H

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
    STEAMWORKS_WRAPPER_API ESteamAPIInitResult SteamSDKAPI_InitFlat(SteamErrMsg *pOutErrMsg);
    STEAMWORKS_WRAPPER_API void SteamSDKAPI_Shutdown();
    STEAMWORKS_WRAPPER_API bool SteamSDKAPI_RestartAppIfNecessary(uint32 unOwnAppID);
    STEAMWORKS_WRAPPER_API void SteamSDKAPI_ReleaseCurrentThreadMemory();
    STEAMWORKS_WRAPPER_API void SteamSDKAPI_WriteMiniDump(uint32 uStructuredExceptionCode, void* pvExceptionInfo, uint32 uBuildID);
    STEAMWORKS_WRAPPER_API void SteamSDKAPI_SetMiniDumpComment(const char *pchMsg);
    STEAMWORKS_WRAPPER_API bool SteamSDKAPI_IsSteamRunning();
}

#endif // STEAMWORKS_WRAPPER_H
