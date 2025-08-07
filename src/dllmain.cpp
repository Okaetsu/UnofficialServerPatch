#include <Mod/CppUserModBase.hpp>
#include <UE4SSProgram.hpp>

// Palworld SDK
#include "SDK/Classes/PalPlayerInventoryData.h"
#include "SDK/Classes/PalMapObjectGenerateEnergyModel.h"

using namespace RC;
using namespace RC::Unreal;
using namespace Palworld;

class UnofficialServerPatch : public RC::CppUserModBase
{
public:
    UnofficialServerPatch() : CppUserModBase()
    {
        ModName = STR("UnofficialServerPatch");
        ModVersion = STR("1.0.0");
        ModDescription = STR("");
        ModAuthors = STR("Okaetsu");

        PalSignatureScanner Scanner{};
        Scanner.Initialize();

        UPalPlayerInventoryData::HookInitializeInServerForInitPlay();
        UPalMapObjectGenerateEnergyModel::HookOnInitializePostProcessInServer();

        Output::send<LogLevel::Verbose>(STR("[{}] v{} loaded successfully!\n"), ModName, ModVersion);
    }

    ~UnofficialServerPatch() override
    {
    }

    auto on_update() -> void override
    {
    }

    auto on_unreal_init() -> void override
    {
    }
};


#define UNOFFICIALSERVERPATCH_API __declspec(dllexport)
extern "C"
{
    UNOFFICIALSERVERPATCH_API RC::CppUserModBase* start_mod()
    {
        return new UnofficialServerPatch();
    }

    UNOFFICIALSERVERPATCH_API void uninstall_mod(RC::CppUserModBase* mod)
    {
        delete mod;
    }
}
