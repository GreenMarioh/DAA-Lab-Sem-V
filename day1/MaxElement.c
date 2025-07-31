#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    int n;
    printf("Enter the number of elements you want to read from the file\n");
    scanf("%d", &n);
    FILE *ptr;
    ptr = fopen("efg.txt", "r");
    if (ptr == NULL)
    {
        printf("Error in file reading\n");
        return 1;
    }
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        if (fscanf(ptr, "%d", &arr[i]) != 1)
        {
            printf("Reached End of File, no numbers ahead\nExiting the program\n");
            fclose(ptr);
            return 1;
        }
    }
    fclose(ptr);

    int maxElement = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxElement)
        {
            maxElement = arr[i];
        }
    }

    int map[maxElement + 1];
    for (int i = 0; i <= maxElement; i++)
    {
        map[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        map[arr[i]]++;
    }

    int maxVal = 0;
    int val = -1;
    for (int i = 0; i <= maxElement; i++)
    {
        if (map[i] > maxVal)
        {
            maxVal = map[i];
            val = i;
        }
    }

    printf("Maximum frequency: %d\n", maxVal);
    printf("The number: %d\n", val);

    return 0;
}
