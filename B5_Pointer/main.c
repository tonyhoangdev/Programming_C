#include <stdio.h>
#include "mylib.h"

int main(void)
{
    const char msg[] = "Hello everyone!!!";
    int arr[] = {1, 2, 3};
    int a, b, i;
    a = 4;
    b = 3;

    printf("Hello\n");
    puts(msg);

    printf("arr = %d", arr[0]);

    for (i = 1; i < 3; i++)
    {
        int d = i;
        printf(", %d", arr[d]);
    }
    printf("\n");

    printf("a = %d\n", a);

    printf("b = %d\n", b);

    printf("Swap: \n");
    swap(&a, &b);

    printf("a = %d\n", a);

    printf("b = %d\n", b);

    printf("Press any key to exit...");
    getchar();
    return 0;
}