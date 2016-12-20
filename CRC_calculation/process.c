#include "process.h"


uint8_t swapBitInByteU8(uint8_t num_input)
{
    uint8_t i,result=0;
    uint8_t shift=0;
    uint8_t mask_number=1;

    for (i=0;i<4;i++)
    {
        shift = 7-(2*i);
        result = result|((num_input&(mask_number<<(7-i)))>>shift);
        result = result|((num_input&(mask_number<<i))<<shift);
    }

    return result;
}

uint32_t swapBitInByte(uint32_t data)
{
    uint32_t retVal;

    retVal = (swapBitInByteU8((data >> 24) & 0xFF) << 24) | (swapBitInByteU8((data >> 16) & 0xFF) << 16) | (swapBitInByteU8((data >> 8) & 0xFF) << 8)| swapBitInByteU8(data & 0xFF);

    return retVal;
}


uint32_t swapBitAndByte(uint32_t num_input)
{
    uint32_t result=0;
    uint8_t i,shift=0;
    uint8_t mask_number=1;
        for (i=0;i<16;i++)
        {
            shift = 31-(2*i);
            result = result|((num_input&(mask_number<<(31-i)))>>shift);
            result = result|((num_input&(mask_number<<i))<<shift);
        }
    return result;
}

uint32_t swapByte(uint32_t data)
{
    uint32_t retVal;

    retVal = ((data >> 24) & 0xFF) | (((data >> 16) & 0xFF) << 8) | (((data >> 8) & 0xFF) << 16)| ((data & 0xFF) << 24);

    return retVal;
}
