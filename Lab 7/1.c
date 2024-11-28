#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

int minof(int *distance,int *visited,int size){
    int min=INT_MAX,minindex;
    for(int i=0;i<size;i++){
        if( visited[i]==0 && min>distance[i]){
            min=distance[i];
            minindex=i;
        }
    }
    return minindex;
}

void sequence(int ** arr,int num,int size){
    int * visited=(int *)malloc(sizeof(int)*size);
    int * distance=(int *)malloc(sizeof(int)*size);
    int * parent=(int *)malloc(sizeof(int)*size);
    for (int  i = 0; i < size; i++)
    {
        visited[i]=0;
        distance[i]=INT_MAX;
        parent[i]=-1;
    }

    distance[num]=0;
    parent[num]=-1;
    int minj;

    for(int i=0;i<size;i++){
        int min=minof(distance,visited,size);
        visited[min]=1;
        for(int j=0;j<size;j++){
            if(arr[min][j] && visited[j]==0 && arr[min][j]<distance[j]){
                parent[j]=min;
                distance[j]=arr[min][j];
                minj=j;
            }
        }
         if (parent[min] != -1) {
            printf("%d %d (%d) ", parent[min], min, arr[min][parent[min]]);
        }
        //printf("%d %d (%d) ",min,minj,arr[min][minj]);
    }
    printf("\n");

}


void totalweight(int ** arr,int size){
    int num=0;
    int * visited=(int *)malloc(sizeof(int)*size);
    int * distance=(int *)malloc(sizeof(int)*size);
    int * parent=(int *)malloc(sizeof(int)*size);
    for (int  i = 0; i < size; i++)
    {
        visited[i]=0;
        distance[i]=INT_MAX;
        parent[i]=-1;
    }

    distance[num]=0;
    parent[num]=-1;

    for(int i=0;i<size;i++){
        int min=minof(distance,visited,size);
        visited[min]=1;
        for(int j=0;j<size;j++){
            if(arr[min][j] && visited[j]==0 && arr[min][j]<distance[j]){
                parent[j]=min;
                distance[j]=arr[min][j];
            }
        }
    }

  int count=0;
  for(int i=0;i<size;i++){
    count+=distance[i];
  }
    printf("%d\n",count);
    
}



int main(){
    int n;
    scanf("%d",&n);
    int size=n;
    int ** arr=(int **)malloc(sizeof(int *)*n);
    for(int i=0;i<size;i++){
        arr[i]=(int *)malloc(sizeof(int)*n);
    }
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    char a;
    int num;
    do{
        scanf("%c",&a);
        if(a=='s'){
            scanf("%d",&num);
            sequence(arr,num,n);
        }
        if(a=='b'){
            totalweight(arr,n);
        }
        if(a=='e') break;
    }while(a!='e');
return 0;
}