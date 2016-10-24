#include "mylib.h"

int add(int a, int b)
{
    return a + b;

}

int sub(int a, int b)
{
    return a - b;
}

int p(int *a)
{
    return *++a;
}

int p2(int *a)
{
    return *a++;
}
