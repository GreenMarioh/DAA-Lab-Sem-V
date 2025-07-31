#include <stdio.h>
void exchange(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void rotate_right(int *p1, int p2)
{
    if (p2 <= 1)
    {
        return;
    }
    for (int i = p2 - 1; i > 0; i--)
    {
        exchange(&p1[i], &p1[i - 1]);
    }
}
int main()
{
    int n;
    printf("Enter the number of elements\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements of array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter value of p2\n");
    int p2;
    scanf("%d", &p2);
    if (p2 > n || p2 <= 0)
    {
        printf("Wrong input\n");
        return 1;
    }
    rotate_right(arr, p2);
    printf("Array after rotating: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
