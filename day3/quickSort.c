#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int comparisons = 0;
int isWorst = 0;
int isBest = 0;

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int arr[], int l, int h)
{
    int p = arr[l];
    int i = l;
    int j = h;

    while (i < j)
    {
        while (arr[i] <= p && i <= h - 1)
        {
            i++;
            comparisons++;
        }
        while (arr[j] >= p && j >= l + 1)
        {
            j--;
            comparisons++;
        }
        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[l], &arr[j]);
    // v ??
    int leftSize = j - l;
    int rightSize = h - j;

    if (leftSize == 0 || rightSize == 0)
        isWorst = 1;
    else if (abs(leftSize - rightSize) <= 1)
        isBest = 1;

    return j;
}

void quickSort(int arr[], int l, int h)
{
    if (l < h)
    {
        int pi = partition(arr, l, h);
        quickSort(arr, l, pi - 1);
        quickSort(arr, pi + 1, h);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *f1 = fopen(argv[1], "r");
    if (!f1)
    {
        printf("Error, no such input file.\n");
        return 1;
    }

    FILE *f2 = fopen(argv[2], "w");
    if (!f2)
    {
        printf("Error, cannot open output file.\n");
        fclose(f1);
        return 1;
    }

    int arr[MAX], n = 0;

    while (fscanf(f1, "%d", &arr[n]) == 1)
    {
        n++;
    }

    fclose(f1);

    printf("\nMAIN MENU (QUICK SORT)\n");
    printf("1. Ascending Data\n");
    printf("2. Descending Data\n");
    printf("3. Random Data\n");
    printf("4. Exit\n");

    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 4)
    {
        printf("Exiting...\n");
        fclose(f2);
        return 0;
    }

    printf("\nBefore Sorting:\n");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("\nAfter Sorting:\n");
    printArray(arr, n);

    for (int i = 0; i < n; i++)
    {
        fprintf(f2, "%d ", arr[i]);
    }

    printf("\nNumber of Comparisons: %d\n", comparisons);

    if (isWorst && !isBest)
        printf("Partitioning Scenario: Worst-case\n");
    else if (isBest && !isWorst)
        printf("Partitioning Scenario: Best-case\n");
    else
        printf("Partitioning Scenario: Mixed-case\n");

    fclose(f2);
    return 0;
}
