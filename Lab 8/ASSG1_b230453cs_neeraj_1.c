#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void prefix(const char * p,int * arr,int m){
    int j=0;
    arr[j]=0;
    int i=1;

    while(i<m){
        if(p[j]==p[i]){
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



void kmp(const char * string,const char * p){
    int n=strlen(string);
    int m=strlen(p);
    int arr[m];

    int index=-1;
    int count=0;

    prefix(p,arr,m);

    int i=0;
    int j=0;

    while(i<n){
        if(p[j]==string[i]){
            i++;
            j++;
        }
        if(j==m){
            index=i-j;
            count++;
            j=arr[j-1];
        }
        else if(i<n && p[j]!=string[i]){
            if(j!=0){
                j=arr[j-1];
            }
            else{
                i++;
            }
        }
    }

    printf("%d %d",index,count);
    }


int main(){
    char string[1000000];
    char p[100000];
    scanf("%s",string);
    scanf("%s",p);
    kmp(string,p);
return 0;
}