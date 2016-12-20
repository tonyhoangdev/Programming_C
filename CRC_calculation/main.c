#include "crc_lib.h"

// 0x31, 0x32
// 0xEBBD
// bit, bit
// note:
// Seed > 0xff is investigating
int main()
{
    uint8_t data[] = {0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x30};
    uint8_t data2[] = {0xd0, 0xdb};

    uint8_t a8 = crc_8bit(0, POLY_CRC_8, &data[1], 4U);
    uint32_t b = crc_16bit(0, POLY_CRC_16, &data[1], 4U);
    uint32_t c = crc_16bit(0, POLY_XMODEM_16, &data[1], 4U);
    uint32_t a = crc_16bit(SEED_CCITT_16, POLY_CCITT_16, &data[1], 4U);
    uint32_t d = crc_32bit(0x0FF, 0x04C11DB7, &data[1], 4U);
    uint32_t e = crc_16bit_LSB(0, 0x8408, &data[1], 4U);
    uint32_t f = crc_16bit(0, 0x8bb7, data2, 2);

    crc_config(CRC_BITS_16, SEED_CCITT_16, POLY_CCITT_16, 0, 0, 0);
    uint32_t crc16 = crc_calculation(0x3132);

    crc_config(CRC_BITS_16, 0, POLY_CCITT_16, 1, 1, 0);
    uint32_t crc16Ker = crc_calculation(0x3132);

    crc_config(CRC_BITS_32, 0x0FF, 0x04C11DB7, 0, 0, 0);
    uint32_t crc32 = crc_calculation(0x31323334);

    printf("CRC-8        : 0x%x\n", a8);
    printf("CRC-16       : 0x%x\n", b);
    printf("CRC-XMODEM-16: 0x%x\n", c);
    printf("CRC-CITT-16  : 0x%x\n", a);
    printf("CRC-KERMIT-16: 0x%x\n", crc16Ker);
    printf("CRC-32       : 0x%x\n", d);
    printf("CRC-16-LSB   : 0x%x\n", e);
    printf("CRC-16-T10-DIF : 0x%x\n", f);
    printf("CRC-16-SI      : 0x%x\n", crc16);
    printf("CRC-32-SI      : 0x%x\n", crc32);
}
