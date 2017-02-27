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
#include "libC.h"

int inWelcome(void);
void delay(int time);

int c = 0;
int a = 4;
const int d = 4;

int main(void)
{
    int arr[] = { 1, 2, 3, 4, 5 };
    char c = arr[3];
    arr[2] = 4;

    delay(100000);

    inWelcome();

    // if (uA > b)
    printf("Hello World!\n");

    // printf("%s", "Enter a number: ");
    // scanf("%d", &a);
    printf("Hello %d\n", LIB_Plus(4, 2));
    printf("Char is %d\n", c);

    printf("Enter any key to exit!!!");
    getch();
    return 0;
}

int inWelcome(void)
{
    printf("Xin chao tat ca moi nguoi %d\n", LIB_MAX);

    return 0;
}

void delay(int time)
{
    while (time--)
        ;
}
