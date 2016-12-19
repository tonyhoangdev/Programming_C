#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define POLY_CCITT_32   0x04C11DB7U
#define POLY_CCITT_16   0x1021U
#define SEED_CCITT_16   0xFFFFU
#define POLY_CRC_16     0x8005U
#define POLY_XMODEM_16  0x8408U
#define POLY_CRC_8      0x07U

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

uint16_t crc_16bit_ref(uint16_t seed,
                       uint32_t polinomial,
                       uint16_t data,
                       bool refin,
                       bool refout,
                       uint16_t xorout)
{
    uint32_t crc;
    uint8_t i;
    crc = seed;
    uint16_t data2 = data;

    if (refin)
    {
        data2 = (data << 8) | (data >> 8);
    }

    crc ^= data2;

    for (i = 0; i < 16; i++)
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

    if (refout)
    {
        crc = (crc << 8) | (crc >> 8);
    }

    crc = crc ^ xorout;

    return crc;
}


int main()
{
    uint8_t data[] = {0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x30};
    uint8_t data2[] = {0xd0, 0xdb};

    uint8_t a8 = crc_8bit(0, POLY_CRC_8, &data[1], 10U);
    uint32_t b = crc_16bit(0, POLY_CRC_16, &data[1], 10U);
    uint32_t c = crc_16bit(0, POLY_XMODEM_16, &data[1], 10U);
    uint32_t a = crc_16bit(SEED_CCITT_16, POLY_CCITT_16, &data[1], 10U);
    uint32_t d = crc_32bit(0x10000FFFU, 0x00001121U, &data[1], 10U);
    uint32_t e = crc_16bit_LSB(0, 0x8408, &data[1], 10U);
    uint32_t f = crc_16bit(0, 0x8bb7, data2, 2);
    uint32_t fs = crc_16bit_ref(0, 0x8bb7, 0xd0db, false, false, 0xFFFF);

    printf("CRC-8        : 0x%x\n", a8);
    printf("CRC-16       : 0x%x\n", b);
    printf("CRC-XMODEM-16: 0x%x\n", c);
    printf("CRC-CITT-16  : 0x%x\n", a);
    printf("CRC-32       : 0x%x\n", d);
    printf("CRC-16-LSB   : 0x%x\n", e);
    printf("CRC-16-T10-DIF : 0x%x\n", f);
    printf("CRC-16-T10-DIF : 0x%x\n", fs);
}
