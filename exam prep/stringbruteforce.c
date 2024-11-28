void stringmatchbruteforce(const char * string,const char * pattern ){
    int n=strlen(string);
    int m=strlen(pattern);
    for(int i=0;i<=n-m;i++){
        int q=0;
        for(int j=0;j<m;j++){
            if(string[i+j]==pattern[j]){
                q++;
            }
        }
        if(q==m) printf("%d ",i);
    }
}