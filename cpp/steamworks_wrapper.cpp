#define STEAMWORKS_WRAPPER_EXPORTS
#include "steamworks_wrapper.h"

extern "C" {
    ESteamAPIInitResult SteamSDKAPI_InitFlat(SteamErrMsg *pOutErrMsg) {
        return ::SteamAPI_InitFlat(pOutErrMsg);
    }
    void SteamSDKAPI_Shutdown() {
        ::SteamAPI_Shutdown();
    }
    bool SteamSDKAPI_RestartAppIfNecessary(uint32 unOwnAppID) {
        return ::SteamAPI_RestartAppIfNecessary(unOwnAppID);
    }
    void SteamSDKAPI_ReleaseCurrentThreadMemory() {
        ::SteamAPI_ReleaseCurrentThreadMemory();
    }
    void SteamSDKAPI_WriteMiniDump(uint32 uStructuredExceptionCode, void* pvExceptionInfo, uint32 uBuildID) {
        ::SteamAPI_WriteMiniDump(uStructuredExceptionCode, pvExceptionInfo, uBuildID);
    }
    void SteamSDKAPI_SetMiniDumpComment(const char *pchMsg) {
        ::SteamAPI_SetMiniDumpComment(pchMsg);
    }
    bool SteamSDKAPI_IsSteamRunning() {
        return ::SteamAPI_IsSteamRunning();
    }
}
