#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int patientid;
    char name[20];
    int severity;
};

void swap(struct node *x, struct node *y)
{
    struct node temp = *x;
    *x = *y;
    *y = temp;
}

void heapifyup(struct node arr[], int index)
{
    int parent = (index - 1) / 2;
    if (index > 0 && arr[index].severity < arr[parent].severity)
    {
        swap(&arr[index], &arr[parent]);
        heapifyup(arr, parent);
    }
}

void heapifydown(struct node arr[], int size, int index)
{
    int smallest = index;
    int left = (2 * index) + 1;
    int right = (2 * index) + 2;

    if (left < size && arr[left].severity < arr[smallest].severity)
    {
        smallest = left;
    }
    if (right < size && arr[right].severity < arr[smallest].severity)
    {
        smallest = right;
    }
    if (smallest != index)
    {
        swap(&arr[smallest], &arr[index]);
        heapifydown(arr, size, smallest);
    }
}

void levelorder(struct node arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i].patientid);
    }
    printf("\n");
}

void admitpatient(struct node arr[], int patid, char name[], int svrty, int *size)
{
    arr[*size].patientid = patid;
    strcpy(arr[*size].name, name);
    arr[*size].severity = svrty;
    (*size)++;
    heapifyup(arr, *size - 1); // start 0 il avum ,oru number insert ayal pinne athu arr[0]il insert akittu 1il nilkum ,so last elemnt arr[size -1]
    levelorder(arr, *size);
}

void treatpatient(struct node arr[], int *size)
{
    if (*size == 0)
    {
        printf("-1\n");
        return;
    }
    printf("%d %s\n", arr[0].patientid, arr[0].name);
    swap(&arr[0], &arr[*size - 1]);
    (*size)--;
    heapifydown(arr, *size, 0);
}

int search(struct node arr[], int patid, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i].patientid == patid)
        {
            return i;
        }
    }
    return -1;
}

void updateseverity(struct node arr[], int patid, int svrty, int size)
{
    int index = search(arr, patid, size);
    if (index == -1)
    {
        printf("-1\n");
        return;
    }
    int old_severity = arr[index].severity;
    arr[index].severity = svrty;
    if (svrty < old_severity)
    {
        heapifyup(arr, index);
    }
    else
    {
        heapifydown(arr, size, index);
    }
    levelorder(arr, size);
}

void querypatient(struct node arr[], int patid, int size)
{
    int index = search(arr, patid, size);
    if (index == -1)
    {
        printf("-1\n");
        return;
    }
    printf("%s %d\n", arr[index].name, arr[index].severity);
}

void copyArray(struct node dest[], struct node src[], int size)
{
    for (int i = 0; i < size; i++)
    {
        dest[i] = src[i];
    }
}

void mostsevere(struct node arr[], int size)
{
    if (size == 0)
    {
        printf("-1\n");
        return;
    }

    int count = size < 3 ? size : 3;
    struct node copy[size];

    copyArray(copy, arr, size);

    for (int i = 0; i < count; i++)
    {
        printf("%d %s %d\n", copy[0].patientid, copy[0].name, copy[0].severity);

        swap(&copy[0], &copy[size - 1]);
        size--;

        heapifydown(copy, size, 0);
    }
}

int main()
{
    int size = 0;
    struct node arr[100];
    int patid, svrty;
    char name[20];
    char choice;

    do
    {
        scanf(" %c", &choice);
        switch (choice)
        {
        case 'a':
            scanf("%d %d %s", &patid, &svrty, name);
            admitpatient(arr, patid, name, svrty, &size);
            break;
        case 'b':
            treatpatient(arr, &size);
            break;
        case 'c':
            scanf("%d %d", &patid, &svrty);
            updateseverity(arr, patid, svrty, size);
            break;
        case 'd':
            scanf("%d", &patid);
            querypatient(arr, patid, size);
            break;
        case 'e':
            mostsevere(arr, size);
            break;
        }
    } while (choice != 'f');

    return 0;
}
