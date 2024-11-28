#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int findjindex(int **arr, int ith, int *count, int size) {
    int adjacent_count = 0;
    for (int j = 0; j < size; j++) {
        if (arr[ith][j] == 1) {  
            if (adjacent_count == *count) {
                return j; 
            }
            adjacent_count++;
        }
    }
    return -1;  
}

int min_ind(int dis[], int check[], int size) {
    int min = INT_MAX;
    int num_index = -1;
    for (int i = 0; i < size; i++) {
        if (!check[i] && dis[i] < min) {
            min = dis[i];
            num_index = i;
        }
    }
    return num_index;
}

void dijkstra(int **arr, int **w8arr, int src, int size) {
    int dis[size];
    int check[size];
    for (int i = 0; i < size; i++) {
        dis[i] = INT_MAX;
        check[i] = 0;
    }
    
    dis[src] = 0;

    for (int i = 0; i < size; i++) {
        int min = min_ind(dis, check, size); 
        if (min == -1) break; 

        check[min] = 1;

        for (int j = 0; j < size; j++) {
            if (arr[min][j] && !check[j] && dis[min] + w8arr[min][j] < dis[j]) {
                dis[j] = dis[min] + w8arr[min][j];
            }
        }
    }

    for (int i = 0; i < size; i++) {
        printf("%d ", dis[i]);
    }
}


int main() {
    int n;
    scanf("%d", &n);
    getchar();  
    int **arr = (int **)malloc(n * sizeof(int *));
    int **w8arr = (int **)malloc(n * sizeof(int *));
    
    for (int i = 0; i < n; i++) {
        arr[i] = (int *)malloc(n * sizeof(int));
        w8arr[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            arr[i][j] = 0; 
            w8arr[i][j] = INT_MAX;  
        }
    }

    for (int t = 0; t < n; t++) {
        char string[256];
        fgets(string, sizeof(string), stdin);
        char *word = strtok(string, " ");
        int i = atoi(word);
        word = strtok(NULL, " ");

        while (word != NULL) {
            int j = atoi(word);
            arr[i - 1][j - 1] = 1;  
            word=strtok(NULL, " ");
        }
    }

    for (int t = 0; t < n; t++) {
        char w8string[256];
        fgets(w8string, sizeof(w8string), stdin);
        char *w8word = strtok(w8string, " ");
        int i = atoi(w8word);
        w8word = strtok(NULL, " ");
        int count = 0;
        while (w8word != NULL) {
            int weight = atoi(w8word);
            int jnum = findjindex(arr, i - 1, &count, n);
            w8arr[i - 1][jnum] = weight;  
            count++;
            w8word = strtok(NULL, " "); 
        }
    }

    int src;
    scanf("%d", &src);

    dijkstra(arr, w8arr, src - 1, n);

    for (int i = 0; i < n; i++) {
        free(arr[i]);
        free(w8arr[i]);
    }
    free(arr);
    free(w8arr);

    return 0;
}
