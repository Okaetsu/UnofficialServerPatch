#include "SDK/Classes/PalMapObjectConcreteModelBase.h"

using namespace RC;
using namespace RC::Unreal;

namespace Palworld {
    UPalMapObjectModel* UPalMapObjectConcreteModelBase::GetModel()
    {
        using GetModel_Signature = UPalMapObjectModel* (*)(UPalMapObjectConcreteModelBase*);

        if (!GetModel_Internal)
        {
            Output::send<LogLevel::Error>(STR("Failed to call UPalMapObjectConcreteModelBase::GetModel because function address was invalid.\n"));
            return nullptr;
        }

        return static_cast<GetModel_Signature>(GetModel_Internal)(this);
    }

    UECustom::FGuid UPalMapObjectConcreteModelBase::GetInstanceId()
    {
        auto InstanceId = *this->GetValuePtrByPropertyNameInChain<UECustom::FGuid>(STR("InstanceId"));
        return InstanceId;
    }

    void UPalMapObjectConcreteModelBase::Initialize(PalSignatureScanner& Scanner)
    {
        Scanner.Add(&GetModel_Internal,
            "E8 ?? ?? ?? ?? 48 85 C0 0F 84 ?? ?? ?? ?? F7 40 08 00 00 00 60 0F 85 ?? ?? ?? ?? 48 89 9C 24 48 03 00 00");
    }
}