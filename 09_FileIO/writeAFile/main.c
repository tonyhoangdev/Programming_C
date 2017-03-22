#include <stdio.h>
#include <stdint.h>

#define STUDENTS 5

int main(void)
{
    int scores[] = { 89, 93, 85, 67, 94 };
    FILE * file = fopen("data.txt", "w");

    if (file != NULL)
    {
        for (int i = 0; i < STUDENTS; i++)
        {
            fprintf(file, "%d\n", scores[i]);
        }
        fclose(file);
    }

    return 0;
}
