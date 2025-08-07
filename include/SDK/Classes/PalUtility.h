#pragma once

#include <Unreal/UObject.hpp>

namespace Palworld {
    class UPalPlayerManager;

    class UPalUtility : public RC::Unreal::UObject {
    public:
        static auto GetDefault() -> UPalUtility*;

        static auto GetPlayerManager(RC::Unreal::UObject* WorldContextObject) -> UPalPlayerManager*;
    private:
        static inline UPalUtility* Self = nullptr;
    };
}
