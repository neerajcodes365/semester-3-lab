// BFS for a connected component starting from a given vertex
void BFS(int **graph, int startVertex, int *visited, int size) {
    int *queue = (int *)malloc(size * sizeof(int)); // Queue for BFS
    int front = 0, rear = 0; // front and rear for the queue

    // Enqueue the starting vertex and mark it as visited
    queue[rear++] = startVertex;
    visited[startVertex] = 1;

    printf("BFS starting from vertex %d: ", startVertex);

    while (front < rear) { // while there are vertices to process
        int currentVertex = queue[front++]; // Dequeue a vertex
        printf("%d ", currentVertex);       // Print the vertex being visited

        // Visit all adjacent vertices
        for (int i = 0; i < size; i++) {
            // Check if there's an edge and if the vertex is unvisited
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                queue[rear++] = i;   // Enqueue the adjacent vertex
                visited[i] = 1;      // Mark it as visited
            }
        }
    }
    printf("\n");

    // Free dynamically allocated memory for the queue
    free(queue);
}

// BFS for a graph that may have disconnected components, starting at a specific vertex
void BFS_Disconnected(int **graph, int size, int startVertex) {
    int *visited = (int *)malloc(size * sizeof(int));

    // Initialize all vertices as not visited
    for (int i = 0; i < size; i++) {
        visited[i] = 0;
    }

    // Start BFS from the specified vertex
    if (!visited[startVertex]) {
        BFS(graph, startVertex, visited, size);
    }

    // Apply BFS on remaining unvisited components (in case there are disconnected parts)
    for (int i = 0; i < size; i++) {
        if (!visited[i]) {
            BFS(graph, i, visited, size);  // Perform BFS for each disconnected component
        }
    }

    free(visited);
}

int main() {
    // Example graph (Adjacency Matrix) for testing
    int size = 6;  // Number of vertices
    int **graph = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        graph[i] = (int *)malloc(size * sizeof(int));
    }
  

    // Start BFS from vertex 2
    BFS_Disconnected(graph, size, 2);

    for (int i = 0; i < size; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}
