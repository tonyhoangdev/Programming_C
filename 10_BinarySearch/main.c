#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

bool search(int key, int arr[], int size)
{
    bool isFound = false;
    int left = 0;
    int right = size - 1;
    int middle;
    int find;

    do
    {
        middle = (left + right) / 2;
        find = arr[middle];

        if (find > key)
        {
            right = middle - 1;
        }
        else if (find < key)
        {
            left = middle + 1;
        }
        else
        {
            isFound = true;
        }

    } while(!isFound && right >= left);

    return isFound;
}

int main(void)
{
    int arr[] = { 1, 3, 5, 6, 7, 9, 10 };
    int key = 11;
    int size = 7;

    if (search(key, arr, size))
    {
        printf("have %d in arr\n", key);
    }
    else
    {
        printf("not have %d in arr\n", key);
    }

    return 0;
}
