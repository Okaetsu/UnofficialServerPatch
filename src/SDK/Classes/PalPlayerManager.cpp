#include "SDK/Classes/PalPlayerManager.h"
#include "Helpers/Casting.hpp"

using namespace RC;
using namespace RC::Unreal;

namespace Palworld {
    RC::Unreal::TMap<UECustom::FGuid, UPalPlayerAccount*> UPalPlayerManager::GetPlayerAccountMap()
    {
        auto PlayerAccountMap = *Helper::Casting::ptr_cast<RC::Unreal::TMap<UECustom::FGuid, UPalPlayerAccount*>*>(this, 0xC0);
        return PlayerAccountMap;
    }
}
