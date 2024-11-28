void dfs(int ** mat ,int index,int matsize,int* arr){
    arr[index]=1;
    for(int i=0;i<matsize;i++){
        if(mat[index][i]==1 && visited[i]==0){
            dfs(mat,i,matsize,arr);
        }

    }
}

void check(int **mat,int n){
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i]=0;
    }
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            dfs(arr,i,n,mat,n);
        }
    }
}