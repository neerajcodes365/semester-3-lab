#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

void prims(int **arr,int num,int size){
    int * visited=(int *)malloc(sizeof(int)*size);
    int * parent=(int *)malloc(sizeof(int)*size);
    int * distance=(int *)malloc(sizeof(int)*size);
    for(int i=0;i<size;i++){
        visited[i]=0;
        parent[i]=-1;
        distance[i]=__INT_MAX__;
    }
    int count=0;
    parent[num]=-1;
    distance[num]=0;
    for(int i=0;i<size;i++){
        int min=minof(visited,distance,size);
        visited[min]=1;
        for(int j=0;j<size;j++){
            if(arr[min][j] && visited[j]==0 && distance[min][j]<distance[j]){
                distance[j]=arr[min][j];
                parent[j]=min;
            }
        }
    }

    int count=0;
    for(int i=0;i<size;i++){
         if(parent[min]!=-1) count+=arr[min][parent[min]];
    }
    printf("%d",count);

}



int main(){
    int n;


return 0;
}