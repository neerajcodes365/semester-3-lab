void bipartate(int ** arr,int size){
    int rear=0,front=0;
    int arr[size];
    int visited[size];
    int coloured[size];
    for(int i=0;i<size;i++){
        visited[i]=0;
        coloured[i]=-1;
    }
    int start=0;
    visited[start]=1;
    arr[rear++]=start;
    coloured[start]=0;
    while(front<rear){
        int num=arr[front++];
        for(int i=0;i<size;i++){
            if(arr[num][i]==1){
                if(coloured[i]==-1){
                    if(coloured[num]==1)coloured[i]=0;
                    else coloured[i]=1;
                }
                else{
                    if(coloured[i]==coloured[num]) return -1;
                }
            }
        }

    }
    

}