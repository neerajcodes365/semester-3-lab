#include <stdbool.h>

int isBipartite(int **arr, int size) {
    int coloured[size];
    int visited[size];
    
    // Initialize coloured and visited arrays
    for (int i = 0; i < size; i++) {
        coloured[i] = -1;  // -1 means uncolored
        visited[i] = 0;    // 0 means unvisited
    }

    int que[size];
    int rear, front;

    // Check each component in the graph
    for (int startvertex = 0; startvertex < size; startvertex++) {
        // Only perform BFS if the vertex is unvisited
        if (visited[startvertex] == 0) {
            rear = -1;
            front = 0;

            // Start BFS from this node
            rear++;
            coloured[startvertex] = 0;  // Start coloring with 0
            que[rear] = startvertex;
            visited[startvertex] = 1;

            while (front <= rear) {
                int val = que[front++];

                for (int i = 0; i < size; i++) {
                    if (arr[val][i] == 1) {  // Check for edges
                        if (coloured[i] == -1) {  // If the node is not colored
                            // Color it with opposite color of `val`
                            coloured[i] = 1 - coloured[val];
                            que[++rear] = i;
                            visited[i] = 1;  // Mark as visited
                        } 
                        else if (coloured[i] == coloured[val]) {
                            // If adjacent nodes have the same color, it's not bipartite
                            return 0;
                        }
                    }
                }
            }
        }
    }

    // If we complete BFS without issues, the graph is bipartite
    return 1;
}
