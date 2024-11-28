#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void heapifyup(int heap[], int index)
{
    int parent = (index - 1) / 2;
    if (index > 0 && heap[index] > heap[parent])
    {
        swap(&heap[index], &heap[parent]);
        heapifyup(heap, parent);
    }
}

void heapifydown(int heap[], int heapsize, int index)
{
    int largest = index;
    int left = (2 * index) + 1;
    int right = (2 * index) + 2;

    if (left < heapsize && heap[largest] < heap[left])
        largest = left;
    if (right < heapsize && heap[largest] < heap[right])
        largest = right;

    if (largest != index)
    {
        swap(&heap[index], &heap[largest]);
        heapifydown(heap, heapsize, largest);
    }
}

bool search(int heap[], int heapsize, int val)
{
    for (int i = 0; i < heapsize; i++)
    {
        if (heap[i] == val)
            return true;
    }
    return false;
}

void insert(int heap[], int *heapsize, int val)
{
    if (!search(heap, *heapsize, val))
    {
        heap[*heapsize] = val;
        heapifyup(heap, (*heapsize)++);
    }
}

int findmax(int heap[], int heapsize)
{
    return (heapsize == 0) ? -1 : heap[0];
}

void extractmax(int heap[], int *heapsize)
{
    int max = heap[0];
    printf("%d ", max);
    swap(&heap[0], &heap[--(*heapsize)]);
    heapifydown(heap, *heapsize, 0);
    for (int i = 0; i < *heapsize; i++)
    {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int extractmax_tohelp(int heap[], int *heapsize)
{
    int max = heap[0];
    swap(&heap[0], &heap[--(*heapsize)]);
    heapifydown(heap, *heapsize, 0);
    return max;
}

void kthlargest(int heap[], int kth, int heapsize)
{
    if (kth > heapsize)
    {
        printf("-1\n");
        return;
    }
    int heap2size = heapsize;
    int arr[heap2size];

    for (int i = 0; i < heapsize; i++)
    {
        arr[i] = heap[i];
    }

    int kthlarge;
    for (int i = 0; i < kth; i++)
    {
        kthlarge = extractmax_tohelp(arr, &heap2size);
    }
    printf("%d\n", kthlarge);
}

void deletekey(int heap[], int *heapSize, int val)
{
    if (*heapSize == 0)
    {
        printf("-1\n");
        return;
    }

    if (heap[0] == val && *heapSize == 1)
    {
        (*heapSize)--;
        printf("0\n");
        return;
    }

    if (!search(heap, *heapSize, val))
    {
        printf("-1\n");
        return;
    }

    for (int i = 0; i < *heapSize; i++)
    {
        if (heap[i] == val)
        {
            swap(&heap[i], &heap[*heapSize - 1]);
            (*heapSize)--;

            if (i < *heapSize)
            {
                if (heap[i] > heap[(i - 1) / 2])
                {
                    heapifyup(heap, i);
                }
                else
                {
                    heapifydown(heap, *heapSize, i);
                }
            }

            break;
        }
    }

    if (*heapSize == 0)
    {
        printf("0\n");
    }
    else
    {
        for (int i = 0; i < *heapSize; i++)
        {
            printf("%d ", heap[i]);
        }
        printf("\n");
    }
}

void replacekey(int heap[], int heapsize, int oldval, int newval)
{
    if (!search(heap, heapsize, oldval))
    {
        printf("%d\n", abs(oldval - newval));
        return;
    }
    for (int i = 0; i < heapsize; i++)
    {
        if (oldval == heap[i])
        {
            heap[i] = newval;
            if (oldval < newval)
            {
                heapifyup(heap, i);
            }
            else
            {
                heapifydown(heap, heapsize, i);
            }
            break;
        }
    }
    for (int i = 0; i < heapsize; i++)
    {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main()
{
    int maxsize = 100;
    int heap[maxsize];
    char choice;
    int heapsize = 0;
    int key, kthelement, oldval, newval;

    do
    {
        scanf(" %c", &choice);
        switch (choice)
        {
        case 'a':
            scanf("%d", &key);
            insert(heap, &heapsize, key);
            break;
        case 'b':
            printf("%d\n", findmax(heap, heapsize));
            break;
        case 'c':
            extractmax(heap, &heapsize);
            break;
        case 'd':
            scanf("%d", &kthelement);
            kthlargest(heap, kthelement, heapsize);
            break;
        case 'e':
            scanf("%d", &key);
            deletekey(heap, &heapsize, key);
            break;
        case 'f':
            scanf("%d %d", &oldval, &newval);
            replacekey(heap, heapsize, oldval, newval);
            break;
        case 'g':
            break;
        }
    } while (choice != 'g');

    return 0;
}
