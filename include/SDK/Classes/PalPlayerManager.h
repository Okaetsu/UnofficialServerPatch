#pragma once

#include "Unreal/UObject.hpp"
#include "Unreal/UnrealCoreStructs.hpp"
#include "Unreal/Core/Containers/Map.hpp"
#include "SDK/Structs/Guid.h"

namespace Palworld {
    class UPalPlayerAccount;

    class UPalPlayerManager : public RC::Unreal::UObject {
    public:
        RC::Unreal::TMap<UECustom::FGuid, UPalPlayerAccount*> GetPlayerAccountMap();
    };
}