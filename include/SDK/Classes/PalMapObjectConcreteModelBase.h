#pragma once

#include "Unreal/UObject.hpp"
#include "SDK/Structs/Guid.h"
#include "SDK/PalSignatureScanner.h"

namespace Palworld {
    class UPalMapObjectModel;
    class UPalMapObjectConcreteModelBase : public RC::Unreal::UObject {
    public:
        UPalMapObjectModel* GetModel();

        UECustom::FGuid GetInstanceId();
    public:
        static void Initialize(PalSignatureScanner& Scanner);
    private:
        static inline void* GetModel_Internal = nullptr;
    };
}