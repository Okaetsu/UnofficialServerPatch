#include "ASMHelper/ASMHelper.hpp"
#include "SDK/Classes/PalMapObjectConcreteModelBase.h"
#include "SDK/Classes/PalPlayerInventoryData.h"
#include "SDK/Classes/PalMapObjectGenerateEnergyModel.h"
#include "SDK/PalSignatureScanner.h"

using namespace RC;
using namespace RC::Unreal;

namespace Palworld {
    void PalSignatureScanner::Initialize()
    {
        UPalMapObjectConcreteModelBase::Initialize(*this);
        UPalPlayerInventoryData::Initialize(*this);
        UPalMapObjectGenerateEnergyModel::Initialize(*this);

        ContainerMap.emplace(ScanTarget::MainExe, ContainerList);
        SinglePassScanner::start_scan(ContainerMap);
    }

    void PalSignatureScanner::Add(void** FuncPtr, const std::string& Pattern)
    {
        SignatureContainer Container = [=]() -> SignatureContainer {
            return {
                {{ Pattern }},
                [=](SignatureContainer& self) {
                    void* FinalPointer = nullptr;
                    FinalPointer = static_cast<void*>(self.get_match_address());

                    if (Pattern.starts_with("E8"))
                    {
                        FinalPointer = ASM::resolve_call(FinalPointer);
                    }

                    *FuncPtr = FinalPointer;

                    self.get_did_succeed() = true;

                    return true;
                },
                [](const SignatureContainer& self) {}
            };
        }();

        ContainerList.push_back(Container);
    }
}