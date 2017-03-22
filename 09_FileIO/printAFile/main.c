#include <stdio.h>

int main(int argc, char * argv[])
{
    if (argc < 2)
    {
        printf("Usage: cat file [file ...]\n");
    }
    else
    {
        for (int i = 1; i < argc; i++)
        {
            /* code */
            FILE * file = fopen(argv[i], "r");
            if (file == NULL)
            {
                printf("cat: %s: No such file or directory\n", argv[i]);
            }
            else
            {
                for (char c = fgetc(file); c != EOF; c = fgetc(file))
                {
                    putchar(c);
                }
                fclose(file);
            }
        }
    }

    return 0;
}
