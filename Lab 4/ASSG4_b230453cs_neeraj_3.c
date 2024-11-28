#include <stdio.h>
#include <stdlib.h>

struct job
{
    int JID;
    int priority;
};

void swap(struct job *x, struct job *y)
{
    struct job temp = *x;
    *x = *y;
    *y = temp;
}

void heapifyup(struct job arr[], int index)
{
    int parent = (index - 1) / 2;
    if (index > 0 && arr[index].priority < arr[parent].priority)
    {
        swap(&arr[index], &arr[parent]);
        heapifyup(arr, parent);
    }
}

void heapifydown(struct job arr[], int size, int index)
{
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && arr[left].priority < arr[smallest].priority)
    {
        smallest = left;
    }
    if (right < size && arr[right].priority < arr[smallest].priority)
    {
        smallest = right;
    }
    if (smallest != index)
    {
        swap(&arr[smallest], &arr[index]);
        heapifydown(arr, size, smallest);
    }
}

void addJob(struct job arr[], int JID, int priority, int *size)
{
    arr[*size].JID = JID;
    arr[*size].priority = priority;
    (*size)++;
    heapifyup(arr, *size - 1);
}

void scheduleJob(struct job arr[], int *size)
{
    if (*size == 0)
    {
        printf("-1\n");
        return;
    }
    printf("%d\n", arr[0].JID);
    swap(&arr[0], &arr[*size - 1]);
    (*size)--;
    heapifydown(arr, *size, 0);
}

void nextJob(struct job arr[], int size)
{
    if (size == 0)
    {
        printf("-1\n");
        return;
    }
    printf("%d\n", arr[0].JID);
}

int searchJob(struct job arr[], int JID, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i].JID == JID)
        {
            return i;
        }
    }
    return -1;
}

void replacePriority(struct job arr[], int JID, int new_priority, int size)
{
    int index = searchJob(arr, JID, size);
    if (index == -1)
    {
        printf("-1\n");
        return;
    }
    int old_priority = arr[index].priority;
    arr[index].priority = new_priority;
    if (new_priority < old_priority)
    {
        heapifyup(arr, index);
    }
    else
    {
        heapifydown(arr, size, index);
    }
}

void displayJobs(struct job arr[], int size)
{
    if (size == 0)
    {
        printf("-1\n");
        return;
    }
    for (int i = 0; i < size; i++)
    {
        printf("%d %d\n", arr[i].JID, arr[i].priority);
    }
}

int main()
{
    int size = 0;
    struct job arr[100];
    int JID, priority, new_priority;
    char choice;

    do
    {
        scanf(" %c", &choice);
        switch (choice)
        {
        case 'a':
            scanf("%d %d", &JID, &priority);
            addJob(arr, JID, priority, &size);
            break;
        case 'b':
            scheduleJob(arr, &size);
            break;
        case 'c':
            nextJob(arr, size);
            break;
        case 'd':
            scanf("%d %d", &JID, &new_priority);
            replacePriority(arr, JID, new_priority, size);
            break;
        case 'e':
            displayJobs(arr, size);
            break;
        }
    } while (choice != 'g');

    return 0;
}
