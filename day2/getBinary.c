// decimal to binary
#include <stdio.h>
#include <stdlib.h>

void getBinary(int num, char *bin, int *idx)
{
    if (num == 0)
        return;
    getBinary(num >> 1, bin, idx);
    bin[(*idx)++] = (num & 1) ? '1' : '0';
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: %s <number_of_integers> <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    if (n <= 0)
    {
        printf("Please provide a positive integer for the number of inputs.\n");
        return 1;
    }

    FILE *inputFile = fopen(argv[2], "r");
    if (!inputFile)
    {
        printf("Error opening %s for reading.\n", argv[2]);
        return 1;
    }

    FILE *outputFile = fopen(argv[3], "w");
    if (!outputFile)
    {
        printf("Error opening %s for writing.\n", argv[3]);
        fclose(inputFile);
        return 1;
    }

    int array[n];

    for (int i = 0; i < n; i++)
    {
        if (fscanf(inputFile, "%d", &array[i]) != 1)
        {
            printf("Error reading integer #%d from %s.\n", i + 1, argv[2]);
            // free(array);
            fclose(inputFile);
            fclose(outputFile);
            return 1;
        }
    }
    fclose(inputFile);

    for (int i = 0; i < n; i++)
    {
        char binary[33] = {0};
        int idx = 0;
        if (array[i] == 0)
        {
            binary[idx++] = '0';
        }
        else
        {
            getBinary(array[i], binary, &idx);
        }
        binary[idx] = '\0';
        fprintf(outputFile, "%s\n", binary);
    }
    fclose(outputFile);

    printf("Content of the first %d decimal(s):\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", array[i]);
    }

    // free(array);
    return 0;
}