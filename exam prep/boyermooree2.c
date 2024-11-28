void BMtable(int *arr,int size,const char * pattern){
    int m=strlen(pattern);
    for(int i=0;i<size;i++){
        arr[i]=m;
    }
    for(int i=0;i<m;i++){
        arr[(unsigned char)pattern[i]]=m-1-i;
    }
}

int BM(int *string,int *pattern){
    int m=strlen(pattern);
    int n=strlen(string);
    int s=0;
    while(s<=n-m){
        int j=m-1;
        while(pattern[j]==string[j+s]){
            j--;
        }
        if(j<0){
            return s;
        }else{
            s+=max(1,j-arr[(unsigned char)pattern[s+j]]);
        }
    }
    return -1;
}