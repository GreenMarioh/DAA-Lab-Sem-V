#include <stdio.h>

struct ITEM
{
    int item_id;
    float item_weight;
    float item_profit;
    float profit_weight_ratio;
};

void swap_793(struct ITEM *a, struct ITEM *b)
{
    struct ITEM tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapify_793(struct ITEM arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].profit_weight_ratio > arr[largest].profit_weight_ratio)
        largest = left;
    if (right < n && arr[right].profit_weight_ratio > arr[largest].profit_weight_ratio)
        largest = right;

    if (largest != i)
    {
        swap_793(&arr[i], &arr[largest]);
        heapify_793(arr, n, largest);
    }
}

void heapSort_793(struct ITEM arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify_793(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--)
    {
        swap_793(&arr[0], &arr[i]);
        heapify_793(arr, i, 0);
    }
    // reverse to get descending order
    for (int i = 0; i < n / 2; i++)
    {
        swap_793(&arr[i], &arr[n - 1 - i]);
    }
}

int main()
{
    int n;
    float capacity;

    printf("Enter the number of items:\n");
    scanf("%d", &n);

    struct ITEM items[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter the profit and weight of item #%d: ", i + 1);
        scanf("%f %f", &items[i].item_profit, &items[i].item_weight);
        items[i].item_id = i + 1;
        items[i].profit_weight_ratio = items[i].item_profit / items[i].item_weight;
    }

    printf("Enter knapsack capacity: \n");
    scanf("%f", &capacity);

    heapSort_793(items, n);

    float total_profit = 0.0;
    float remaining_capacity = capacity;
    float amount_taken[n];

    for (int i = 0; i < n; i++)
    {
        if (items[i].item_weight <= remaining_capacity)
        {
            amount_taken[i] = 1.0;
            total_profit += items[i].item_profit;
            remaining_capacity -= items[i].item_weight;
        }
        else
        {
            amount_taken[i] = remaining_capacity / items[i].item_weight;
            total_profit += items[i].item_profit * amount_taken[i];
            remaining_capacity = 0;
        }
    }

    printf("\nItem No  Profit    Weight    Amount Taken\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d        %.6f   %.6f   %.6f\n",
               items[i].item_id,
               items[i].item_profit,
               items[i].item_weight,
               amount_taken[i]);
    }

    printf("Maximum profit: %.6f\n", total_profit);

    return 0;
}
