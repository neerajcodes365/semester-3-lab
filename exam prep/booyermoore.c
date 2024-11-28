int max(int a,int b){
    return a>b?a:b;
}

void BMtable(int * arr,int size,const char * pattern){
    int m=strlen(pattern);
    for(int i=0;i<size;i++){
        arr[i]=m;
    }
    for(int i=0;i<m;i++){
       arr[(unsigned char)pattern[i]]=m-i-1;
    }
}

int BM(int *string,int* pattern){
    int n=strlen(string);
    int m=strlen(pattern);

    int * arr=(int *)malloc(sizeof(int)*256);

    BMtable(arr,256,pattern);

    int s=0;
    while(s<=n-m){
        int j=m-1;
        while(j>=0 && pattern[j]==string[s+j]){
            j--;
        }
        if(j<0){
            return s;
        }else{
            s+=max(1,j-BMtable[(unsigned char)string[s+j]]);
        }
    }
    return -1;
}


int s=0;
while(s<=n-m){
    int j=m-1;
    if(string[j+s]==pattern[j]){
        j--;
    }
    if(j<0){
        return s;
    }else{
        s+=max(1,j-BMtable[(unsigned char)string[s+j]]);
    }
}













int main() {
    char *text = (char *)malloc(10000005 * sizeof(char));
    char *pattern = (char *)malloc(100005 * sizeof(char));

    fgets(text, 10000005, stdin);
    text[strlen(text) - 1] = '\0';
    fgets(pattern, 100005, stdin);
    pattern[strlen(pattern) - 1] = '\0';

    int result = BM(arr,256,text,pattern);

    printf("%d\n", result);

    free(text);
    free(pattern);

    return 0;
}