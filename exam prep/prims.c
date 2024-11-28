void prims(int ** arr,int size){
    int distance[size];
    int parent[size];
    int visited[size];
    for(int i=0;i<size;i++){
        distance[i]=INT_MAX;
        parent[i]=-1;
        visited[i]=-1;
    }
    distance[0]=0;
    parent[0]=-1;
    for(int i=0;i<size;i++){
        int val=min(distance,visited,size);
        visited[val]=1;
        for(int j=0;j<size;j++){
            if(arr[val][j]==1 && visited[j]==0 && arr[val][j]<distance[j]){
                distance[j]=arr[val][j];
                parent[j]=val;
            }
        }
    }

    for(int i=0;i<size;i++){
        if(parent[i]!=-1){
            sum+=arr[parent[i]][i];
        }
    }
}