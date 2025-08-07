#pragma once

#include "Unreal/UObject.hpp"

namespace Palworld {
    class UPalBuildProcess;

    class UPalMapObjectModel : public RC::Unreal::UObject {
    public:
        UPalBuildProcess* GetBuildProcess();
    private:
    };
}