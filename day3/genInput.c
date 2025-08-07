#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_SIZE 300
#define MAX_SIZE 500

// Generate a random number between [low, high]
int getRandom(int low, int high)
{
    return low + rand() % (high - low + 1);
}

// Writes array to a file
void writeToFile(const char *filename, int arr[], int n)
{
    FILE *fp = fopen(filename, "w");
    if (!fp)
    {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    for (int i = 0; i < n; i++)
    {
        fprintf(fp, "%d ", arr[i]);
    }
    fclose(fp);
    printf("Generated: %s (%d entries)\n", filename, n);
}

int main()
{
    srand(time(0)); // Seed for random generation

    int n = getRandom(MIN_SIZE, MAX_SIZE);
    int *arr = (int *)malloc(n * sizeof(int));
    if (!arr)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Ascending
    for (int i = 0; i < n; i++)
        arr[i] = i + 1;
    writeToFile("inAsce.dat", arr, n);

    // Descending
    for (int i = 0; i < n; i++)
        arr[i] = n - i;
    writeToFile("inDesc.dat", arr, n);

    // Random
    for (int i = 0; i < n; i++)
        arr[i] = getRandom(1, 999); // Random numbers from 1 to 999
    writeToFile("inRand.dat", arr, n);

    free(arr);
    return 0;
}
