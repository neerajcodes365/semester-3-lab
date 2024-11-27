#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void linear(int hasharr[], int keyarr[], int n, int m) {
    int collision = 0;
    for (int i = 0; i < m; i++) {
        int key = keyarr[i] % n;
        while (hasharr[key] != -1) {
            key = (key + 1) % n;
            collision++;
        }
        hasharr[key] = keyarr[i];
        printf("%d ", key);
    }
    printf("\n%d\n", collision);
}

void quadratic(int hasharr[], int keyarr[], int n, int m) {
     for (int i = 0; i < n; i++) {
        hasharr[i] = -1;
    }
    int collision = 0;
    for (int i = 0; i < m; i++) {
        int indexhelp = 1;
        int ogikey = keyarr[i] % n;
        int key = ogikey;
        while (hasharr[key] != -1) {
            key = (ogikey + (indexhelp * indexhelp)) % n;
            collision++;
            indexhelp++;
        }
        hasharr[key] = keyarr[i];
        printf("%d ", key);
    }
    printf("\n%d\n", collision);
}

int key=hash(i);
int index=1;
while(arr[key]!=-1){
    key=(key+(index *index))%size;
index++;
if(index==size) break;
}
arr[index]=key;

int prime(int n) {
    for (int i = n-1; i >= 2; i--) {//n-1 venamtto
        int flag = 1;
        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            return i;
        }
    }
    return 2;  
}

void double_(int hasharr[], int keyarr[], int n, int m) {
     for (int i = 0; i < n; i++) {
        hasharr[i] = -1;
    }
    int collision = 0;
    int r = prime(n);
    for (int i = 0; i < m; i++) {
        int j = 0;
        int key = keyarr[i];
        int h1 = key % n;
        int h2 = r - (key % r);
        int index = h1;
        while (hasharr[index] != -1) {
            collision++;
            j++;
            index = (h1 + j * h2) % n;
        }
        hasharr[index] = key;
        printf("%d ", index);
    }
    printf("\n%d\n", collision);
}

int main() {
    char choice;
    int n, m;
    scanf("%d %d", &n, &m);
    
    int *keyarr = (int *)malloc(m * sizeof(int));
    int *hasharr = (int *)malloc(n * sizeof(int));
    
    for (int i = 0; i < m; i++) {
        scanf("%d", &keyarr[i]);
    }
    for (int i = 0; i < n; i++) {
        hasharr[i] = -1;
    }

    do {
        scanf(" %c", &choice);  
        switch (choice) {
            case 'a':
                linear(hasharr, keyarr, n, m);
                break;
            case 'b':
                quadratic(hasharr, keyarr, n, m);
                break;
            case 'c':
                double_(hasharr, keyarr, n, m);
                break;
            case 'd':
                break;
        }
    } while (choice != 'd');

    free(keyarr);
    free(hasharr);
    return 0;
}
