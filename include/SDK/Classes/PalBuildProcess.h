#pragma once

#include "Unreal/UObject.hpp"
#include "SDK/Enum/EPalBuildProcessState.h"

namespace Palworld {
    class UPalBuildProcess : public RC::Unreal::UObject {
    public:
        EPalBuildProcessState GetBuildState();
    };
}