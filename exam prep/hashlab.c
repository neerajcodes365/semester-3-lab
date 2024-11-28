#include<stdio.h>
#include<stdlib.h>
#include<math.h>


void linear(int hasharr[],int keyarr[],int n,int m){
    for (int i = 0; i < n; i++) {
        hasharr[i] = -1;
    }
    int col=0;
    for(int i=0;i<m;i++){
        int j=0;
        while(hasharr[((keyarr[i]+j)%n)]!=-1){
            j++;
            col++;
            if(j>=n) return;
        }
        hasharr[((keyarr[i]+j)%n)]=keyarr[i];
        printf("%d ",((keyarr[i]+j)%n));
    }
    printf("\n%d\n",col);
}

// int search(int hasharr[],int val,int size){
//     int a=hash(val);
//     int j=0;
//     while(((a+j)%size) !=-1){
//         if(hasharr[((a+j)%size)]==val){
//             return (a+j) % size;
//         }
//         j++;
//         if(j>=size)return -1;
//     }
//     return -1;
// }







void quadratic(int hasharr[], int keyarr[], int n, int m) {

for (int i = 0; i < n; i++) {
        hasharr[i] = -1;
    }
    int col=0;
    for(int i=0;i<m;i++){
        int j=0;
        while(hasharr[(keyarr[i]+(j*j))%n] !=-1){
                j++;
                col++;
                if(j>=n)return;
        }
        hasharr[(keyarr[i]+(j*j))%n]=keyarr[i];
        printf("%d ",(keyarr[i]+(j*j))%n);
    }
    printf("\n%d\n",col);
    return;
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
