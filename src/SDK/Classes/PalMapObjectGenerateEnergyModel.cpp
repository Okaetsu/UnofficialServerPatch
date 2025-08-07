#include "Unreal/FProperty.hpp"
#include "SDK/Structs/Guid.h"
#include "SDK/Classes/PalBuildProcess.h"
#include "SDK/Classes/PalMapObjectModel.h"
#include "SDK/Classes/PalMapObjectGenerateEnergyModel.h"

using namespace RC;
using namespace RC::Unreal;

namespace Palworld {
    void UPalMapObjectGenerateEnergyModel::Initialize(PalSignatureScanner& Scanner)
    {
        Scanner.Add(&OnInitializePostProcessInServer_Internal,
            "40 55 57 41 55 41 56 48 8B EC 48 83 EC 48 48 8B 42 10");
    }

    void UPalMapObjectGenerateEnergyModel::HookOnInitializePostProcessInServer()
    {
        if (!OnInitializePostProcessInServer_Internal)
        {
            Output::send<LogLevel::Error>(STR("HookOnInitializePostProcessInServer failed: OnInitializePostProcessInServer_Internal is not initialized.\n"));
            return;
        }

        OnInitializePostProcessInServer_Hook = safetyhook::create_inline(reinterpret_cast<void*>(OnInitializePostProcessInServer_Internal),
            reinterpret_cast<void*>(OnInitializePostProcessInServer));
    }

    void UPalMapObjectGenerateEnergyModel::OnInitializePostProcessInServer(UPalMapObjectGenerateEnergyModel* This, RC::Unreal::UObject* param_1)
    {
        try
        {
            auto Model = This->GetModel();
            if (!Model)
            {
                throw std::runtime_error("Model was null.");
            }

            auto BuildProcess = Model->GetBuildProcess();
            if (!BuildProcess)
            {
                throw std::runtime_error("Build Process was null.");
            }

            auto BuildState = BuildProcess->GetBuildState();
            if (BuildState != EPalBuildProcessState::Completed)
            {
                throw std::runtime_error("Build State was 0.");
            }
        }
        catch (const std::exception& e)
        {
            auto InstanceId = This->GetInstanceId();
            Output::send<LogLevel::Error>(STR("UPalMapObjectGenerateEnergyModel::OnInitializePostProcessInServer was skipped for a building to prevent a crash. Affected building: {} ({}), {}\n"),
                                          This->GetName(), InstanceId.ToString(), RC::to_generic_string(e.what()));
            return;
        }

        OnInitializePostProcessInServer_Hook.call<void>(This, param_1);
    }
}