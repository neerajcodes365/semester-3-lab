#include<stdio.h>
#include<stdlib.h>

int hash(long long int num, int k) {
    // Split Aadhaar into three parts of four digits each
    long long int part1 = num / 100000000;           // First 4 digits
    long long int part2 = (num / 10000) % 10000;     // Next 4 digits
    long long int part3 = num % 10000;               // Last 4 digits

    // Calculate the sum of the three parts
    int sum = part1 + part2 + part3;

    // Return the index using mod with k
    return sum % k;
}

void display(long long int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == -1) 
            printf("-1 ");
        else 
            printf("%lld ", arr[i]);
    }
    printf("\n");
}

void rehash(long long int** arr, int* size, long long int duplicate[], int top) {
    int oldSize = *size;
    *size *= 2;
    *arr = (long long int*)realloc(*arr, (*size) * sizeof(long long int));

    // Reinitialize the resized hash table
    for (int i = oldSize; i < *size; i++) {
        (*arr)[i] = -1;
    }

    // Reinsert all elements into the resized hash table
    for (int j = 0; j < top; j++) {
        int index = hash(duplicate[j], *size);
        int i = 0;
        while ((*arr)[(index + (i * i)) % (*size)] != -1) {
            i++;
        }
        (*arr)[(index + (i * i)) % (*size)] = duplicate[j];
    }
}

void insert(long long int arr[], long long int val, int* size, int* top, long long int duplicate[]) {
    // Check if rehashing is needed (when table is 60% full)
    if (*top >= (0.6 * (*size))) {
        rehash(&arr, size, duplicate, *top);
    }

    // Perform the regular insertion with quadratic probing
    int index = hash(val, *size);
    int i = 0;
    while (arr[(index + (i * i)) % (*size)] != -1) {
        i++;
    }
    // Insert the value into the hash table
    arr[(index + (i * i)) % (*size)] = val;
    
    // Keep track of inserted values for rehashing
    duplicate[*top] = val;
    (*top)++;
}

int main() {
    int size;
    scanf("%d", &size);

    // Initialize the hash table and auxiliary array to store duplicates
    long long int* arr = (long long int*)malloc(sizeof(long long int) * size);
    long long int* duplicate = (long long int*)malloc(sizeof(long long int) * 500);  // Arbitrary large size for duplicate array

    for (int i = 0; i < size; i++) {
        arr[i] = -1;  // Mark all bins as empty initially
    }

    int top = 0;
    long long int val;
    char choice;

    // Process the input commands
    do {
        scanf(" %c", &choice);
        switch (choice) {
            case 'i':  // Insert command
                scanf("%lld", &val);
                insert(arr, val, &size, &top, duplicate);
                break;
            case 'd':  // Display command
                display(arr, size);
                break;
            case 'e':  // Exit command
                break;
        }
    } while (choice != 'e');

    // Free allocated memory
    free(arr);
    free(duplicate);

    return 0;
}
