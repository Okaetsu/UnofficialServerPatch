#pragma once

#include "SDK/Classes/PalMapObjectConcreteModelBase.h"
#include "SDK/PalSignatureScanner.h"
#include "safetyhook.hpp"

namespace Palworld {
    class UPalMapObjectGenerateEnergyModel : public UPalMapObjectConcreteModelBase {
    public:
        static void Initialize(PalSignatureScanner& Scanner);

        static void HookOnInitializePostProcessInServer();
    private:
        static inline void* OnInitializePostProcessInServer_Internal = nullptr;
        static inline SafetyHookInline OnInitializePostProcessInServer_Hook{};
        static void OnInitializePostProcessInServer(UPalMapObjectGenerateEnergyModel* This, RC::Unreal::UObject* param_1);
    };
}