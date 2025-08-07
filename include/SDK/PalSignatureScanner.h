#pragma once

#include <string>
#include <vector>
#include <Signatures.hpp>
#include <SigScanner/SinglePassSigScanner.hpp>

namespace Palworld {
    class PalSignatureScanner {
    public:
        void Initialize();

        void Add(void** FuncPtr, const std::string& Pattern);
    private:
        std::vector<RC::SignatureContainer> ContainerList;
        RC::SinglePassScanner::SignatureContainerMap ContainerMap;
    };
}