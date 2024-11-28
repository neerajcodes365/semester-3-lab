#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<stdio.h>
void table(const char * pattern,int * arr,int m){
    int j=0;
    int i=1;
    arr[0]=0;
    while(i<m){
        if(pattern[j]==pattern[i]){
            arr[i]=j+1;
            j++;
            i++;
        }
        else{
            if(j!=0){
                j=arr[j-1];
            }else{
                arr[i]=0;
                i++;
            }
        }
    }
}
void kmp(const char * string,const char * pattern){
    int n=strlen(string);
    int m=strlen(pattern);
    int *arr=(int * )malloc(sizeof(int)*m);
    table(pattern,arr,m);
    int count=0;
    int j=0,i=0;
    while(i<n){
        if(pattern[j]==string[i]){
            j++;
            i++;
        }
        if(j==m){
            printf("%d ",i-j);
            j=arr[j-1];
            count++;
        }
        else if(i<n && pattern[j]!=string[i]){
            if(j!=0){
                j=arr[j-1];
            }else{
                i++;
            }
        }
    }
}

int main(){
char string[100];
char pattern[100];
scanf("%s %s",string,pattern);
kmp(string,pattern);
return 0;
}


int i=0,j=0;
while(i<n){
    if(pattern[j]==string[i]){
        i++;
        j++;
    }
    if(j==m){
        printf("%d",i-j);
        j=arr[j-1];
    }
    if(i<n && pattern[j]!=string[i]){
        if(j!=0){
            j=arr[j-1];
        }else{
            i++;
        }
        
    }
}




int i=0;j=0;
while(i<n){
    if(string[i]==pattern[j]){
        i++;
        j++;
    }

    if(j==m){
        printf("%d",i-j);
        j=arr[j-1];
    }
    if(i<n && pattern[j]!=string[i]){
        if(j!=0){
            j=arr[j-1];
        }
        else{
            i++;
        }
    }
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