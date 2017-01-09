#include "crc_lib.h"

/* cal */
uint32_t g_data = 0; /* seed or data */
uint32_t g_dataCal = 0; /* seed or data */
uint32_t g_polinomial = 0;

/* in, out */
uint32_t g_dataIn = 0;
uint32_t g_dataOut = 0;
uint32_t g_polinomialIn = 0;
bool g_crcWidth = 0;            /* 0: 16 bits, 1: 32 bits*/
uint8_t g_writeTranspose = false;
uint8_t g_readTranspose = false;
bool g_dataAsSeed = 0;          /* 0: data,    1: seed */
uint32_t g_xorOut = 0;

uint16_t crc_16bit(uint16_t seed,
                   uint32_t polinomial,
                   uint8_t *data,
                   uint32_t length)
{
    uint32_t crc;
    uint8_t i, j;
    crc = seed;

    for (j = 0; j < length; j++)
    {
        crc ^= data[j] << 8;

        for (i = 0; i < 8; i++)
        {
            if (crc & 0x8000)
            {
                crc = (crc << 1) ^ polinomial;
            }
            else
            {
                crc <<= 1;
            }
        }
    }

    return crc;
}

uint8_t crc_8bit(uint8_t seed,
                 uint8_t polinomial,
                 uint8_t *data,
                 uint32_t length)
{
    uint8_t crc;
    uint8_t i, j;
    crc = seed;

    for (j = 0; j < length; j++)
    {
        crc ^= data[j];

        for (i = 0; i < 8; i++)
        {
            if (crc & 0x80)
            {
                crc = (crc << 1) ^ polinomial;
            }
            else
            {
                crc <<= 1;
            }
        }
    }

    return crc;
}

uint16_t crc_16bit_LSB(uint16_t seed,
                       uint32_t polinomial,
                       uint8_t *data,
                       uint32_t length)
{
    uint16_t crc;
    uint8_t i, j;
    crc = seed;

    for (j = 0; j < length; j++)
    {
        crc ^= data[j];

        for (i = 0; i < 8; i++)
        {
            if (crc & 0x0001)
            {
                crc = (crc >> 1) ^ polinomial;
            }
            else
            {
                crc >>= 1;
            }

        }
    }

    return crc;
}

uint32_t crc_32bit(uint32_t seed,
                   uint32_t polinomial,
                   uint8_t *data,
                   uint32_t length)
{
    uint8_t j,i;
    uint32_t crc;
    crc = seed;

    for(j = 0; j < length; j++)
    {
        crc ^= data[j] << 24;

        for(i = 0; i < 8; i++)
        {
            if(crc & 0x80000000)
            {
                crc = (crc << 1) ^ polinomial;
            }
            else
            {
                crc <<= 1;
            }
        }
    }

    return crc;
}

void crc_config(crc_bit_width_t crcWidth,
                uint32_t seed,
                uint32_t polynomial,
                crc_transpose_t writeTranspose,
                crc_transpose_t readTranspose,
                uint32_t xorout)
{
    g_crcWidth = crcWidth;
    g_dataAsSeed = 1;
    crc_write_data(seed);
    g_dataAsSeed = 0;
    g_polinomialIn = polynomial;
    g_writeTranspose = writeTranspose;
    g_readTranspose = readTranspose;
    g_xorOut = xorout;
}

uint32_t crc_calculation(uint32_t data)
{
    uint8_t i;
    uint32_t crc = g_data;
    g_polinomial = g_polinomialIn;
    crc_write_data(data);
    crc ^= g_dataCal;

    if (g_crcWidth == 0) /* 16 bits */
    {
        for (i = 0; i < 16; i++)
        {
            if (crc & 0x8000)
            {
                crc = (crc << 1) ^ g_polinomial;
            }
            else
            {
                crc <<= 1;
            }
        }
    }
    else if (g_crcWidth == 1) /* 32 bits */
    {
        for (i = 0; i < 32; i++)
        {
            if (crc & 0x80000000)
            {
                crc = (crc << 1) ^ g_polinomial;
            }
            else
            {
                crc <<= 1;
            }
        }
    }
    else
    {
    }

    g_data = crc ^ g_xorOut;
    crc_read_data();
    return g_dataOut;
}

uint32_t crc_calculation_u8(uint8_t * data, uint32_t len)
{
    return 0;
}

void crc_write_data(uint32_t data)
{
    g_dataIn = data;

    switch (g_writeTranspose)
    {
        case CRC_TRANSPOSE_NONE:
            if (g_dataAsSeed)
            {
                g_data = data;
            }
            else
            {
                g_dataCal = data;
            }
            break;
        case CRC_TRANSPOSE_BITS:
            if (g_dataAsSeed)
            {
                g_data = swapBitInByte(data);
            }
            else
            {
                g_dataCal = swapBitInByte(data);
            }
            break;
        case CRC_TRANSPOSE_BITS_AND_BYTES:
            if (g_dataAsSeed)
            {
                g_data = swapBitAndByte(data);
            }
            else
            {
                g_dataCal = swapBitAndByte(data);
            }
            break;
        case CRC_TRANSPOSE_BYTES:
            if (g_dataAsSeed)
            {
                g_data = swapByte(data);
            }
            else
            {
                g_dataCal = swapByte(data);
            }
            break;
    }
}

void crc_read_data()
{
    switch (g_readTranspose)
    {
        case CRC_TRANSPOSE_NONE:
            g_dataOut = g_data;
            break;
        case CRC_TRANSPOSE_BITS:
            g_dataOut = swapBitInByte(g_data);
            break;
        case CRC_TRANSPOSE_BITS_AND_BYTES:
            g_dataOut = swapBitAndByte(g_data);
            break;
        case CRC_TRANSPOSE_BYTES:
            g_dataOut = swapByte(g_data);
            break;
    }
}
