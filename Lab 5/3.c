#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void dfs(int **arr, int size, int v, int visited[]) {
    visited[v] = 1;  
    for (int i = 0; i < size; i++) {
        if (arr[v][i] == 1 && !visited[i]) {
            dfs(arr, size, i, visited);  
        }
    }
}

int countStronglyConnectedComponents(int **arr, int size) {
    int visited[size];
    
    int **transpose = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        transpose[i] = (int *)malloc(size * sizeof(int));
    }

    for (int i = 0; i < size; i++) visited[i] = 0;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            transpose[i][j] = arr[j][i];  
        }
    }

    int count = 0;
    
    for (int i = 0; i < size; i++) {
        if (!visited[i]) {
            dfs(transpose, size, i, visited);  
            count++;  
        }
    }

    for (int i = 0; i < size; i++) {
        free(transpose[i]);
    }
    free(transpose);

    return count;
}

int dfsCycle(int **arr, int size, int v, int visited[], int stackFlag[]) {
    visited[v] = 1;
    stackFlag[v] = 1;  

    for (int i = 0; i < size; i++) {
        if (arr[v][i] == 1) {  
            if (!visited[i] && dfsCycle(arr, size, i, visited, stackFlag)) {
                return 1;  
            } else if (stackFlag[i]) {
                return 1;  
            }
        }
    }
    stackFlag[v] = 0;  
    return 0;  
}

int isDAG(int **arr, int size) {
    int visited[size];
    int stackFlag[size];
    
    for (int i = 0; i < size; i++) {
        visited[i] = 0;
        stackFlag[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        if (!visited[i]) {
            if (dfsCycle(arr, size, i, visited, stackFlag)) {
                return -1;  
            }
        }
    }
    return 1;  
}





int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        arr[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            arr[i][j] = 0; 
        }
    }

        for (int i = 0; i < n; i++) {
        int u;
        scanf("%d", &u);  
        char line[256];
        fgets(line, sizeof(line), stdin);  
        char *token = strtok(line, " ");
        
        
        while (token != NULL) {
            int v = atoi(token);
            arr[u - 1][v - 1] = 1;  
            token = strtok(NULL, " ");
        }
    }

  
    char command;
    while (1) {
        scanf(" %c", &command);
        if (command == 'a') {
            int res = isDAG(arr, n);
            printf("%d\n", res); 
        } else if (command == 'b') {
            int sccCount = countStronglyConnectedComponents(arr, n);
            printf("%d\n", sccCount); 
        } else if (command == 'x') {
            break; 
        }
    }

    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
