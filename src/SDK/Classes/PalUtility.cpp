#include <Unreal/UObjectGlobals.hpp>
#include <Unreal/UFunction.hpp>
#include <SDK/Classes/PalUtility.h>
#include <SDK/Classes/PalPlayerManager.h>

using namespace RC;
using namespace RC::Unreal;

namespace Palworld {
    auto UPalUtility::GetDefault() -> UPalUtility*
    {
        if (!Self)
        {
            Self = UObjectGlobals::StaticFindObject<UPalUtility*>(nullptr, nullptr, STR("/Script/Pal.Default__PalUtility"));
        }
        return Self;
    }

    auto UPalUtility::GetPlayerManager(UObject* WorldContextObject) -> UPalPlayerManager*
    {
        static auto Function = UObjectGlobals::StaticFindObject<UFunction*>(nullptr, nullptr, STR("/Script/Pal.PalUtility:GetPlayerManager"));

        if (!Function) {
            throw std::runtime_error{ "Function /Script/Pal.PalUtility:GetPlayerManager not found." };
        }

        struct {
            UObject* WorldContextObject;
            UPalPlayerManager* ReturnValue;
        }params;

        params.WorldContextObject = WorldContextObject;

        GetDefault()->ProcessEvent(Function, &params);

        return params.ReturnValue;
    }
}
