int min(int * visited,int * distance,int size){
    int n=size;
    int minindex=-1;
    int minval=INT_MAX;
    for(int i=0;i<n;i++){
        if(visited[i]==0 && distance[i]<minval){
            minindex=i;
            minval=distance[i];
        }
    }
    return minindex;
}



void dijkstra(int ** arr,int size,int **w8arr,int w8size,int sourcenode){
    int visited[size];
    int distance[size];
    int n=size;
    for(int i=0;i<size;i++){
        visited[i]=0;
        distance[i]=__INT_MAX__;
    }
    distance[sourcenode]=0;
    int val;
    for(int i=0;i<n;i++){
        val=min(visited,distance,size);
        visited[val]=1;
        for(int j=0;j<n;j++){
            if(arr[val][j]==1 && visited[j]==0){
                if(distance[val]+w8arr[val][j]<distance[j]){
                    distance[j]=distance[val]+w8arr[val][j];
                }
            }
        }
    }
}