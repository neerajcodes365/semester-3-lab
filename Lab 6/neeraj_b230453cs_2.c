#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
int min(int a,int b){
    return a>b?b:a;
}
void floydwarshall(int ** arr,int size ){

    for(int k=0;k<size;k++){
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                arr[i][j]=min(arr[i][j],arr[i][k]+arr[k][j]);
            }
        }
    }

for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
        printf("%d ",arr[i][j]);
    }
    printf("\n");
}

}
int main(){
int n;
scanf("%d",&n);
int **arr=(int **)malloc(sizeof(int*)*n);
for(int i=0;i<n;i++){
    arr[i]=(int *)malloc(sizeof(int)*n);
}
int a;
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        scanf("%d",&a);
        if(a==-1) a=1000;
        arr[i][j]=a;
    }
}
floydwarshall(arr,n);
return 0;
}