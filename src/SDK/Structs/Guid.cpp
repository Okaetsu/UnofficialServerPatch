#include <SDK/Structs/Guid.h>
#include <Objbase.h>
#include "DynamicOutput/DynamicOutput.hpp"

namespace UECustom {
    FGuid::FGuid() : A(0), B(0), C(0), D(0) {}

    FGuid::FGuid(uint32_t InA, uint32_t InB, uint32_t InC, uint32_t InD) : A(InA), B(InB), C(InC), D(InD) {}

    void FGuid::invalidate()
    {
        A = B = C = D = 0;
    }

    bool FGuid::is_valid() const
    {
        return ((A | B | C | D) != 0);
    }

    uint32_t FGuid::GetA()
    {
        return A;
    }

    uint32_t FGuid::GetB()
    {
        return B;
    }

    uint32_t FGuid::GetC()
    {
        return C;
    }

    uint32_t FGuid::GetD()
    {
        return D;
    }

    std::wstring FGuid::ToString()
    {
        std::wostringstream woss;
        woss << std::hex << std::setfill(L'0') << std::nouppercase
            << std::setw(8) << A << L'-'
            << std::setw(4) << ((B >> 16) & 0xFFFF) << L'-'
            << std::setw(4) << (B & 0xFFFF) << L'-'
            << std::setw(4) << ((C >> 16) & 0xFFFF) << L'-'
            << std::setw(4) << (C & 0xFFFF)
            << std::setw(8) << D;

        return woss.str();
    }
}