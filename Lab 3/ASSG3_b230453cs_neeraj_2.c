#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *next;
};

int hash(int key, int size)
{
    return key % size;
}

void sortedinsert(struct node **sortedref, struct node *newnode)
{
    if (*sortedref == NULL || (*sortedref)->key >= newnode->key)
    {
        newnode->next = *sortedref;
        *sortedref = newnode;
    }
    else
    {
        struct node *current = *sortedref;
        while (current->next != NULL && current->next->key < newnode->key)
        {
            current = current->next;
        }
        newnode->next = current->next;
        current->next = newnode;
    }
}

void insertionsort(struct node **headref)
{
    struct node *sorted = NULL;
    struct node *current = *headref;
    while (current != NULL)
    {
        struct node *next = current->next;
        sortedinsert(&sorted, current);
        current = next;
    }
    *headref = sorted;
}

void insert(struct node *arr[], int key, int size)
{
    int index = hash(key, size);
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->key = key;
    newnode->next = arr[index];
    arr[index] = newnode;
    insertionsort(&(arr[index]));
}

int search(struct node *arr[], int key, int size)
{
    int index = hash(key, size);
    struct node *temp = arr[index];
    int position = 0;
    while (temp != NULL)
    {
        if (temp->key == key)
        {
            printf("%d %d\n", index, position + 1);
            return 1;
        }
        temp = temp->next;
        position++;
    }
    printf("-1\n");
    return 0;
}

void delete(struct node *arr[], int key, int size)
{
    int index = hash(key, size);
    struct node *temp = arr[index];
    struct node *prev = NULL;
    int position = 0;
    while (temp != NULL)
    {
        if (temp->key == key)
        {
            if (prev == NULL)
            {
                arr[index] = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }
            free(temp);
            printf("%d %d\n", index, position + 1);
            return;
        }
        prev = temp;
        temp = temp->next;
        position++;
    }
    printf("-1\n");
}

int keypresent(struct node *arr[], int key, int size)
{
    int index = hash(key, size);
    struct node *temp = arr[index];
    while (temp != NULL)
    {
        if (temp->key == key)
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void update(struct node *arr[], int oldkey, int newkey, int size)
{
    if (keypresent(arr, newkey, size))
    {
        printf("-1\n");
        return;
    }
    if (keypresent(arr, oldkey, size))
    {
        delete (arr, oldkey, size);
        insert(arr, newkey, size);
    }
    else
    {
        printf("-1\n");
    }
}

void print(struct node *arr[], int index)
{
    struct node *temp = arr[index];
    if (temp == NULL)
    {
        printf("-1\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d ", temp->key);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    int size;
    scanf("%d", &size);
    struct node *arr[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = NULL;
    }

    char choice;
    int key, oldkey, newkey, index;

    do
    {
        scanf(" %c", &choice);
        switch (choice)
        {
        case 'a':
            scanf("%d", &key);
            insert(arr, key, size);
            break;
        case 'b':
            scanf("%d", &key);
            search(arr, key, size);
            break;
        case 'c':
            scanf("%d", &key);
            delete (arr, key, size);
            break;
        case 'd':
            scanf("%d", &oldkey);
            scanf("%d", &newkey);
            update(arr, oldkey, newkey, size);
            break;
        case 'e':
            scanf("%d", &index);
            print(arr, index);
            break;
        case 'f':
            break;
        }
    } while (choice != 'f');

    return 0;
}
