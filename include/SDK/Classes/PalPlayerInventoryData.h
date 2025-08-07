#pragma once

#include "Unreal/UObject.hpp"
#include "Unreal/UnrealCoreStructs.hpp"
#include "SDK/PalSignatureScanner.h"
#include "SDK/Structs/Guid.h"
#include "safetyhook.hpp"

namespace Palworld {
    class UPalPlayerInventoryData : public RC::Unreal::UObject {
    public:
        UECustom::FGuid GetOwnerPlayerUId();
    public:
        static void Initialize(PalSignatureScanner& Scanner);

        static void HookInitializeInServerForInitPlay();
    private:
        static inline void* InitializeInServerForInitPlay_Internal = nullptr;
        static inline SafetyHookInline InitializeInServerForInitPlay_Hook{};
        static void OnInitializeInServerForInitPlay(UPalPlayerInventoryData* This);
    };
}