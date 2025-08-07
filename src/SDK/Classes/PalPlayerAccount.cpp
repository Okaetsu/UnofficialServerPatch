#include "SDK/Classes/PalPlayerAccount.h"
#include "Helpers/Casting.hpp"

using namespace RC;
using namespace RC::Unreal;

namespace Palworld {
    UObject* UPalPlayerAccount::GetIndividualHandle()
    {
        auto IndividualHandle = *Helper::Casting::ptr_cast<UObject**>(this, 0x70);
        return IndividualHandle;
    }
}