#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int comparisons = 0;
int isWorst = 0;
int isBest = 0;

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int left[n1], right[n2];
    for (int i = 0; i < n1; i++)
        left[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        comparisons++;
        if (left[i] <= right[j])
        {
            arr[k++] = left[i++];
        }
        else
        {
            arr[k++] = right[j++];
        }
    }

    while (i < n1)
        arr[k++] = left[i++];
    while (j < n2)
        arr[k++] = right[j++];
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);

        // Best/worst case tracking
        int leftSize = m - l + 1;
        int rightSize = r - m;
        if (leftSize == 0 || rightSize == 0)
            isWorst = 1;
        else if (abs(leftSize - rightSize) <= 1)
            isBest = 1;
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
        n++;
    fclose(f1);

    printf("\nMAIN MENU (MERGE SORT)\n");
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

    mergeSort(arr, 0, n - 1);

    printf("\nAfter Sorting:\n");
    printArray(arr, n);

    for (int i = 0; i < n; i++)
        fprintf(f2, "%d ", arr[i]);

    printf("\nNumber of Comparisons: %d\n", comparisons);

    if (isWorst && !isBest)
        printf("Merge scenario: Worst-case\n");
    else if (isBest && !isWorst)
        printf("Merge scenario: Best-case\n");
    else
        printf("Merge scenario: Mixed-case\n");

    fclose(f2);
    return 0;
}
