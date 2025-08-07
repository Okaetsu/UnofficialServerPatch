#include "SDK/Classes/PalMapObjectModel.h"

namespace Palworld {
    UPalBuildProcess* UPalMapObjectModel::GetBuildProcess()
    {
        auto BuildProcess = this->GetValuePtrByPropertyNameInChain<UPalBuildProcess*>(STR("BuildProcess"));
        if (!BuildProcess)
        {
            return nullptr;
        }

        return *BuildProcess;
    }
}