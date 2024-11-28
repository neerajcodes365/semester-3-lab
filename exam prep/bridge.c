int bridge(int ** arr,int size){
    int count=0;
    int totalconnectedcomponets=tcom(arr,size);
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(arr[i][j]==1){
                arr[i][j]=arr[j][i]=0;
                int check=tcom(arr,size);
                if(check>totalconnectedcomponets) count++;
                arr[i][j]=arr[j][i]=0;
            }
        }
    }
    return count/2;
}

int countBridges(int adj[MAX][MAX], int V) {
    int bridge_count = 0;
    
    // Calculate the initial number of connected components
    int initial_components = countComponents(adj, V);
    
    // Loop through all edges
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (adj[i][j] == 1) { // There's an edge
                // Remove the edge
                adj[i][j] = adj[j][i] = 0;
                
                // Count the number of connected components after removing the edge
                int new_components = countComponents(adj, V);
                
                // If the number of components increased, this edge is a bridge
                if (new_components > initial_components) {
                    bridge_count++;
                }
                
                // Restore the edge
                adj[i][j] = adj[j][i] = 1;
            }
        }
    }
    return bridge_count;
}