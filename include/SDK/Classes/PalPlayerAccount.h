#pragma once

#include "Unreal/UObject.hpp"

namespace Palworld {
    class UPalPlayerAccount : public RC::Unreal::UObject {
    public:
        RC::Unreal::UObject* GetIndividualHandle();
    };
}