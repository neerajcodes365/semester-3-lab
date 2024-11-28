int min(int a ,int b){
    return a>b?a:b;
}

void flyodwarshal(int **arr,int size){
    for(int k=0;k<size;k++){
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                arr[i][j]=min((arr[i][k]+arr[k][j]),arr[i][j]);
            }
        }
    }
}