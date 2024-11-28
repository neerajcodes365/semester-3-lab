

void dfs(int **arr,int index,int size,int * visited){
    visited[index]=1;
    for(int i=0;i<size;i++){
        if(arr[index][i]==1 && !visited[i]){
            dfs(arr,i,size,visited);
        }
    }
}


int main(){

    int size ;
    //dynamic array 2d 
    arr[size][size];

    int start;
    scanf("%d",&start);

    int * visited=(int *)malloc(sizeof(int)*size);
    for(int i=0;i<size;i++){
        visited[i]=0;
    }


    if(!visited[start]){
        dfs(arr,start,size,visited);
    }
    for(int i=0;i<size;i++){
        if(!visited[i]) dfs(arr,i,size,visited);
    }
}   