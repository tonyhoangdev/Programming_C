#ifndef CRC_LIB_H
#define CRC_LIB_H

#include "process.h"

/* cal */
extern uint32_t g_data;
extern uint32_t g_dataCal;
extern uint32_t g_polinomial;

/* in, out */
extern uint32_t g_dataIn;
extern uint32_t g_dataOut;
extern uint32_t g_polinomialIn;
extern bool g_crcWidth;
extern uint8_t g_writeTranspose;
extern uint8_t g_readTranspose;
extern bool g_dataAsSeed;
extern uint32_t g_xorOut;

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

void crc_config(crc_bit_width_t crcWidth,
                uint32_t seed,
                uint32_t polynomial,
                crc_transpose_t writeTranspose,
                crc_transpose_t readTranspose,
                uint32_t xorout);

uint32_t crc_calculation(uint32_t data);

uint32_t crc_calculation_u8(uint8_t * data, uint32_t len);

void crc_write_data(uint32_t data);

void crc_read_data();

#endif /* CRC_LIB_H */
