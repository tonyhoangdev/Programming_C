#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>


#define POLY_CCITT_32   0x04C11DB7U
#define POLY_CCITT_16   0x1021U
#define SEED_CCITT_16   0xFFFFU
#define POLY_CRC_16     0x8005U
#define POLY_XMODEM_16  0x8408U
#define POLY_CRC_8      0x07U


typedef enum
{
    CRC_BITS_16 = 0U,   /*!< Generate 16-bit CRC code */
    CRC_BITS_32 = 1U    /*!< Generate 32-bit CRC code */
} crc_bit_width_t;

typedef enum
{
    CRC_TRANSPOSE_NONE              = 0x00U,    /*!< No transpose */
    CRC_TRANSPOSE_BITS              = 0x01U,    /*!< Transpose bits in bytes */
    CRC_TRANSPOSE_BITS_AND_BYTES    = 0x02U,    /*!< Transpose bytes and bits in bytes */
    CRC_TRANSPOSE_BYTES             = 0x03U     /*!< Transpose bytes */
} crc_transpose_t;

uint16_t crc_16bit(uint16_t seed,
                   uint32_t polinomial,
                   uint8_t *data,
                   uint32_t length);

uint8_t crc_8bit(uint8_t seed,
                 uint8_t polinomial,
                 uint8_t *data,
                 uint32_t length);

uint16_t crc_16bit_LSB(uint16_t seed,
                       uint32_t polinomial,
                       uint8_t *data,
                       uint32_t length);

uint32_t crc_32bit(uint32_t seed,
                   uint32_t polinomial,
                   uint8_t *data,
                   uint32_t length);

/* TODO */
uint16_t crc_16bit_ref(uint16_t seed,
                       uint32_t polinomial,
                       uint16_t data,
                       bool refin,
                       bool refout,
                       uint16_t xorout);

void crc_config(crc_bit_width_t crcWidth,
                uint32_t seed,
                uint32_t polynomial,
                crc_transpose_t writeTranspose,
                crc_transpose_t readTranspose,
                uint32_t xorout);

uint32_t crc_calculation();

void crc_write_data(uint32_t data);

void crc_read_data();

#endif /* MAIN_H */