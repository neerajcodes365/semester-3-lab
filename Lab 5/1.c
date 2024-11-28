#include <stdio.h>
#include <stdlib.h>

void dfs(int **arr, int index, int *visited, int size) {
    visited[index] = 1;
    for (int j = 0; j < size; j++) {
        if (arr[index][j] == 1 && visited[j] == 0) {
            dfs(arr, j, visited, size);
        }
    }
}

int noOfConnectedComponents(int **arr, int size) {
    int count = 0;
    int *visited = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        visited[i] = 0;
    }
    for (int i = 0; i < size; i++) {
        if (visited[i] == 0) {
            dfs(arr, i, visited, size);
            count++;
        }
    }
    return count;
}

void dfshelp(int **arr, int index, int *visited, int size, int *x) {
    visited[index] = 1;
    (*x)++;

    for (int j = 0; j < size; j++) {
        if (arr[index][j] == 1 && visited[j] == 0) {
            dfshelp(arr, j, visited, size, x);
        }
    }
}

void sort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void sizeOfComponents(int **arr, int size) {
    int totalComponents = noOfConnectedComponents(arr, size);

    if (totalComponents == 0) {
        printf("0\n");
        return;
    }

    int *finalarr = (int *)malloc(sizeof(int) * totalComponents);
    int count = 0;
    int *visited = (int *)malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++) {
        visited[i] = 0;
    }

    int j = 0;

    for (int i = 0; i < size; i++) {
        if (visited[i] == 0) {
            int x = 0;
            dfshelp(arr, i, visited, size, &x);
            finalarr[j++] = x;
        }
    }

    sort(finalarr, totalComponents);

    for (int i = 0; i < totalComponents; i++) {
        printf("%d ", finalarr[i]);
    }
    printf("\n");
}

void dfsArticulation(int u, int parent, int *visited, int *discovery, int *low, int *ap, int **arr, int *time, int size) {
    visited[u] = 1;
    discovery[u] = low[u] = ++(*time);
    int children = 0;

    for (int v = 0; v < size; v++) {
        if (arr[u][v] == 1) {
            if (!visited[v]) {
                children++;
                dfsArticulation(v, u, visited, discovery, low, ap, arr, time, size);
                low[u] = (low[u] < low[v]) ? low[u] : low[v];

                if (parent != -1 && low[v] >= discovery[u]) {
                    ap[u] = 1;
                }
            } else if (v != parent) {
                low[u] = (low[u] < discovery[v]) ? low[u] : discovery[v];
            }
        }
    }

    if (parent == -1 && children > 1) {
        ap[u] = 1;
    }
}

void noOfArticulationPoints(int **arr, int size) {
    int *visited = (int *)malloc(size * sizeof(int));
    int *discovery = (int *)malloc(size * sizeof(int));
    int *low = (int *)malloc(size * sizeof(int));
    int *ap = (int *)malloc(size * sizeof(int));
    int time = 0;

    for (int i = 0; i < size; i++) {
        visited[i] = 0;
        discovery[i] = -1;
        low[i] = -1;
        ap[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        if (!visited[i]) {
            dfsArticulation(i, -1, visited, discovery, low, ap, arr, &time, size);
        }
    }

    int apCount = 0;
    for (int i = 0; i < size; i++) {
        if (ap[i]) {
            apCount++;
        }
    }
    printf("%d\n", apCount);
}

void dfsBridges(int u, int parent, int *visited, int *disc, int *low, int **arr, int *bridges, int size) {
    static int time = 0;
    visited[u] = 1;
    disc[u] = low[u] = ++time;

    for (int v = 0; v < size; v++) {
        if (arr[u][v] == 1) {
            if (!visited[v]) {
                dfsBridges(v, u, visited, disc, low, arr, bridges, size);
                low[u] = (low[u] < low[v]) ? low[u] : low[v];

                if (low[v] > disc[u]) {
                    (*bridges)++;
                }
            } else if (v != parent) {
                low[u] = (low[u] < disc[v]) ? low[u] : disc[v];
            }
        }
    }
}

void noOfBridges(int **arr, int size) {
    int *visited = (int *)malloc(size * sizeof(int));
    int *disc = (int *)malloc(size * sizeof(int));
    int *low = (int *)malloc(size * sizeof(int));
    int bridges = 0;

    for (int i = 0; i < size; i++) {
        visited[i] = 0;
        disc[i] = -1;
        low[i] = -1;
    }

    for (int i = 0; i < size; i++) {
        if (!visited[i]) {
            dfsBridges(i, -1, visited, disc, low, arr, &bridges, size);
        }
    }

    printf("%d\n", bridges);
}

int main() {
    int n;
    scanf("%d", &n);
    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        arr[i] = (int *)malloc(n * sizeof(int));
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    char choice;
    while (1) {
        scanf(" %c", &choice);  
        switch (choice) {
            case 'a':
                printf("%d\n", noOfConnectedComponents(arr, n));
                break;
            case 'b':
                sizeOfComponents(arr, n);
                break;
            case 'c':
                noOfBridges(arr, n);
                break;
            case 'd':
                noOfArticulationPoints(arr, n);
                break;
            case 'x':
                return 0;
        }
    }

    return 0;
}
