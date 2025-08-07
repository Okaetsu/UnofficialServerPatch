#pragma once

#include "Unreal/Core/CoreTypes.hpp"

namespace Palworld {
    enum class EPalBuildProcessState : RC::Unreal::uint8 {
        Building,
        Completed,
    };
}