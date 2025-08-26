#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person
{
    int id;
    char name[50];
    int age;
    int height;
    int weight;
};

struct person *heap = NULL;
int size = 0;

void swap_2305793(struct person *a, struct person *b)
{
    struct person temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify_2305793(int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left].age < heap[smallest].age)
        smallest = left;

    if (right < size && heap[right].age < heap[smallest].age)
        smallest = right;

    if (smallest != i)
    {
        swap_2305793(&heap[i], &heap[smallest]);
        minHeapify_2305793(smallest);
    }
}

void maxHeapify_2305793(int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left].weight > heap[largest].weight)
        largest = left;

    if (right < size && heap[right].weight > heap[largest].weight)
        largest = right;

    if (largest != i)
    {
        swap_2305793(&heap[i], &heap[largest]);
        maxHeapify_2305793(largest);
    }
}

void buildMinHeap_2305793()
{
    for (int i = size / 2 - 1; i >= 0; i--)
        minHeapify_2305793(i);
}

void buildMaxHeap_2305793()
{
    for (int i = size / 2 - 1; i >= 0; i--)
        maxHeapify_2305793(i);
}

void displayYoungestWeight_2305793()
{
    if (size == 0)
    {
        printf("Heap is empty!\n");
        return;
    }
    printf("Weight of youngest student: %.2f kg\n", heap[0].weight * 0.453592);
}

void insertMinHeap_2305793(struct person newPerson)
{
    size++;
    heap = realloc(heap, size * sizeof(struct person));
    heap[size - 1] = newPerson;

    int i = size - 1;
    while (i != 0 && heap[(i - 1) / 2].age > heap[i].age)
    {
        swap_2305793(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void deleteOldestPerson_2305793()
{
    if (size == 0)
    {
        printf("Heap is empty!\n");
        return;
    }

    int maxAgeIndex = 0;
    for (int i = 1; i < size; i++)
    {
        if (heap[i].age > heap[maxAgeIndex].age)
            maxAgeIndex = i;
    }

    printf("Deleted: %s (Age %d)\n", heap[maxAgeIndex].name, heap[maxAgeIndex].age);

    heap[maxAgeIndex] = heap[size - 1];
    size--;
    heap = realloc(heap, size * sizeof(struct person));
    buildMinHeap_2305793();
}

void readData_2305793()
{
    FILE *fp = fopen("students.txt", "r");
    if (!fp)
    {
        printf("Error opening file!\n");
        return;
    }

    fscanf(fp, "%d", &size);
    heap = malloc(size * sizeof(struct person));

    for (int i = 0; i < size; i++)
    {
        fscanf(fp, "%d %s %d %d %d", &heap[i].id, heap[i].name,
               &heap[i].age, &heap[i].height, &heap[i].weight);
    }
    fclose(fp);

    printf("Data Loaded Successfully!\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d %s %d %d %d\n", heap[i].id, heap[i].name,
               heap[i].age, heap[i].height, heap[i].weight);
    }
}

int main()
{
    int choice;
    struct person newP;

    while (1)
    {
        printf("\nMAIN MENU (HEAP)\n");
        printf("1. Read Data\n");
        printf("2. Create a Min-heap based on the age\n");
        printf("3. Create a Max-heap based on the weight\n");
        printf("4. Display weight of the youngest person\n");
        printf("5. Insert a new person into the Min-heap\n");
        printf("6. Delete the oldest person\n");
        printf("7. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            readData_2305793();
            break;
        case 2:
            buildMinHeap_2305793();
            printf("Min-Heap created.\n");
            break;
        case 3:
            buildMaxHeap_2305793();
            printf("Max-Heap created.\n");
            break;
        case 4:
            displayYoungestWeight_2305793();
            break;
        case 5:
            printf("Enter id, name, age, height, weight: ");
            scanf("%d %s %d %d %d", &newP.id, newP.name, &newP.age, &newP.height, &newP.weight);
            insertMinHeap_2305793(newP);
            printf("Person inserted.\n");
            break;
        case 6:
            deleteOldestPerson_2305793();
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
