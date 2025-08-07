#include "Helpers/Casting.hpp"
#include "SDK/Classes/PalUtility.h"
#include "SDK/Classes/PalPlayerAccount.h"
#include "SDK/Classes/PalPlayerManager.h"
#include "SDK/Classes/PalPlayerInventoryData.h"

using namespace RC;
using namespace RC::Unreal;

namespace Palworld {
    UECustom::FGuid Palworld::UPalPlayerInventoryData::GetOwnerPlayerUId()
    {
        auto OwnerPlayerUId = *Helper::Casting::ptr_cast<UECustom::FGuid*>(this, 0x1A4);
        return OwnerPlayerUId;
    }

    void UPalPlayerInventoryData::Initialize(PalSignatureScanner& Scanner)
    {
        Scanner.Add(&InitializeInServerForInitPlay_Internal,
            "40 53 57 41 56 48 83 EC 30 48 8B F9 E8 ?? ?? ?? ?? 48 8B CF E8");
    }

    void UPalPlayerInventoryData::HookInitializeInServerForInitPlay()
    {
        if (!InitializeInServerForInitPlay_Internal)
        {
            Output::send<LogLevel::Error>(STR("HookInitializeInServerForInitPlay failed: InitializeInServerForInitPlay_Internal is not initialized.\n"));
            return;
        }

        InitializeInServerForInitPlay_Hook = safetyhook::create_inline(reinterpret_cast<void*>(InitializeInServerForInitPlay_Internal),
            reinterpret_cast<void*>(OnInitializeInServerForInitPlay));
    }

    void UPalPlayerInventoryData::OnInitializeInServerForInitPlay(UPalPlayerInventoryData* This)
    {
        try
        {
            auto PlayerManager = UPalUtility::GetPlayerManager(This);
            if (!PlayerManager)
            {
                throw std::runtime_error("PlayerManager was null.");
            }

            auto PlayerAccountMap = PlayerManager->GetPlayerAccountMap();

            auto OwnerPlayerUId = This->GetOwnerPlayerUId();

            auto PlayerAccount = PlayerAccountMap.Find(OwnerPlayerUId);
            if (!PlayerAccount)
            {
                throw std::runtime_error(std::format("PlayerAccount was null for {}.", RC::to_string(OwnerPlayerUId.ToString())));
            }

            auto IndividualHandle = (*PlayerAccount)->GetIndividualHandle();
            if (!IndividualHandle)
            {
                throw std::runtime_error(std::format("IndividualHandle was null for {}.", RC::to_string(OwnerPlayerUId.ToString())));
            }
        }
        catch (const std::exception& e)
        {
            Output::send<LogLevel::Error>(STR("UPalPlayerInventoryData::OnInitializeInServerForInitPlay was skipped for a player to prevent a crash: {}\n"), 
                                            RC::to_generic_string(e.what()));
            return;
        }

        InitializeInServerForInitPlay_Hook.call<void>(This);
    }
}