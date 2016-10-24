#include <stdio.h>
#include "mylib.h"

int main(void)
{
    const char msg[] = "Hello everyone!!!";
    int arr[] = {1, 2, 3};
    int a, b, c, i;
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

    c = add(a, b);
    printf("a + b = %d\n", c);

    c = add3(a, b, c);
    printf("a + b + c = %d\n", c);

    c = sub(a, b);
    printf("a - b = %d\n", c);

    c = p(arr);
    printf("++c = %d\n", c);

    c = p2(arr);
    printf("c++ = %d\n", c);

    puts("Hellodf");

    printf("Press any key to exit...");
    getchar();
    return 0;
}