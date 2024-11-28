void bfs(int * visited,int vissize,int ** arr,int arrsize,int index){
    int front=0;
    int rear=-1;
    int* que=(int *)malloc(sizeof(int)*vissize);
    rear++;
    que[rear]=index;
    visited[index]=1;

    while(front<=rear){
        int i=que[front++];
        for(int j=0;j<arrsize;j++){
            if(arr[i][j]==1 && visited[j]==0){
                rear++;
                que[rear]=j;
                visited[j]=1;
            }
        }
    }
}


     

void disconnected(int ** arr, int size){
    int visited[size];
    for(int i=0;i<size;i++){
        visited[i]=0;
    }
    for(int i=0;i<size;i++){
        if(visited[i]==0){
            bfs(visited,size,arr,size,i);
        }
    }
}