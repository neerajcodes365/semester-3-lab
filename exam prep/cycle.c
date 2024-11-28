int cycle(int ** arr,int size){
    int rear=-1;
    int front=0;
    int que[size];

    int visited[size];
    int parent[size];
    for(int i=0;i<size;i++){
        visited[i]=0;
        parent[i]=-1;
    }
    int index=0;
    rear++;

    arr[rear]=index;
    visited[index]=1;
    parent[index]=-1;

    for(int i=0;i<size;i++){
        int val=que[front++];
        for(int j=0;j<size;j++){
        if(arr[val][j]==1 && visited[j]==0){
            rear++;
            que[rear]=j;
            visited[j]=1;
            parent[j]=val;
        }
        else if(arr[val][j]==1 && visited[j]==1){
            if(parent[val]!=j) return 1;
        }
    }
}
return 0;
}