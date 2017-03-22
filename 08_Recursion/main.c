#include <stdio.h>
#include <stdint.h>

// Infinite loop
void foo(char * str)
{
    printf("%s\n", str);
    foo(str);
}

// Factorial
uint32_t factorial(uint32_t n)
{
    // Base case
    if (n < 2)
    {
        return 1;
    }

    // Recursive case
    return n * factorial(n-1);
}

int main(void)
{
    uint32_t n = 5;

    printf("Hello\n");
    printf("factorial of %d = %d\n", n, factorial(n));

    return 0;
}
