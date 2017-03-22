#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

void swap(int * a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubbleSort(int * arr, int size, bool orderAsc)
{
    bool isSorted = false;
    bool hasSwap = false;
    int counter = 0;

    do
    {
        hasSwap = false;

        for (int i = 0; i < size - 1 - counter; i++)
        {
            if (orderAsc)
            {
                if (arr[i] > arr[i + 1])
                {
                    swap(&arr[i], &arr[i + 1]);
                    hasSwap = true;
                }
            }
            else
            {
                if (arr[i] < arr[i + 1])
                {
                    swap(&arr[i], &arr[i + 1]);
                    hasSwap = true;
                }
            }
        }

        if (hasSwap == false)
        {
            isSorted = true;
        }
        else
        {
            counter++;
        }

    } while (!isSorted);

}

int main(void)
{
    int arr[] = { 10, 3, 5, 6, 4, 9, 10 };
    int size = 6;

    // ASC
    bubbleSort(arr, size, true);

    for (int i = 0; i < size; ++i)
    {
        printf("%d ", arr[i]);
    }

    // DES
    bubbleSort(arr, size, false);

    printf("\n");
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
