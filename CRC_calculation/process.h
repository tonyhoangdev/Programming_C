#ifndef PROCESS_H
#define PROCESS_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

uint8_t swapBitInByteU8(uint8_t num_input);
uint32_t swapBitInByte(uint32_t data);
uint32_t swapBitAndByte(uint32_t num_input);
uint32_t swapByte(uint32_t data);

#endif /* PROCESS_H */