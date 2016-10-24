#include <stdio.h>
#include <stdint.h>

typedef struct
{
    uint8_t p1;
    uint8_t p2;
} struct_byte_t;

typedef struct
{
    uint8_t p1 : 1;
    uint8_t p2 : 1;
} struct_bit_t;

int main()
{
    printf("Hello\n");

    printf("Bo nho cap phat cho struct_byte_t: %d\n", sizeof(struct_byte_t));
    printf("Bo nho cap phat cho struct_bit_t: %d\n", sizeof(struct_bit_t));

    printf("Press any key to exit...");
    getchar();
    return 0;
}