void prims(int ** arr,int size,int index){
   
    int * visited=(int *)malloc(sizeof(int)*size);
    int * parent=(int *)malloc(sizeof(int)*size);
    int * distance=(int *)malloc(sizeof(int)*size);
    for(int i=0;i<size;i++){
        visited[i]=0;
        parent[i]=-1;
        distance[i]=INT_MAX;
    }
    distance[index]=0;
    for(int i=0;i<size;i++){
        int val=min(visited,distance,size);
        visited[val]=1;
        for(int j=0;j<size;j++){
            if(arr[val][j]==1 && visited[j]==0 && arr[val][j]<distance[j] ){
                distance[j]=arr[val][j];
                parent[j]=val;
            }
        }
    }   
}

void dijistra(int **arr,int size,int index){

     int * visited=(int *)malloc(sizeof(int)*size);
    int * distance=(int *)malloc(sizeof(int)*size);

     for(int i=0;i<size;i++){
        visited[i]=0;
        distance[i]=INT_MAX;
    }
    visited[index]=0;

    for(int i=0;i<size;i++){
        int val=min(visited,distance,size);
        visited[val]=1;
        for(int j=0;j<size;j++){
            if(arr[val][j]==1 && visited[j]==0 && arr[val][j]+distance[val]<distance[j]){
                distance[j]=arr[val][j]+distance[val];
            }
        }
    }


}