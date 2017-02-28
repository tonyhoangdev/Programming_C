/*
 ============================================================================
 Name        : main.c
 Author      : MinhHT3
 Version     :
 Copyright   : HTM
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <conio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

int inWelcome(void);
void delay(int time);

static const uint8_t s_state[] = { 1U, 2U, 3U, 4U, 5U, 6U };
static uint8_t s_xucSac[3U];

int main(int argc, char *argv[])
{
    uint8_t i;
    uint8_t sum = 0;

    if (argc > 1)
    {
        printf("%d : ", time(argv[1]) / 90);
    }
    else
    {
        srand(time(NULL));
    }

    s_xucSac[0] = s_state[rand() % 6];
    s_xucSac[1] = s_state[rand() % 6];
    s_xucSac[2] = s_state[rand() % 6];


    for (i = 0; i < 3; ++i)
    {
        printf("Xuc sac %d: %d\n", i + 1, s_xucSac[i]);
        sum += s_xucSac[i];
    }

    printf("Tong: %d ==> ", sum);
    if (sum >= 11)
    {
        printf("Tai.\n");
    }
    else
    {
        printf("Xiu.\n");
    }

    // printf("Enter any key to exit!!!");
    // getch();
    return 0;
}

void delay(int time)
{
    while (time--)
        ;
}
