#include "SDK/Classes/PalBuildProcess.h"

namespace Palworld {
    EPalBuildProcessState UPalBuildProcess::GetBuildState()
    {
        auto State = *this->GetValuePtrByPropertyNameInChain<EPalBuildProcessState>(STR("State"));
        return State;
    }
}
