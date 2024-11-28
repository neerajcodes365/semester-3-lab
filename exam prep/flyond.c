void flyond(int ** arr,int size){
    for(int k=0;k<size;k++){
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(arr[i][k]!=INT_MAX && arr[k][j]!=INT_MAX){
                    arr[i][j]=min(arr[i][j],arr[i][k]+arr[k][j]);
                }
            }
        }
    }
}