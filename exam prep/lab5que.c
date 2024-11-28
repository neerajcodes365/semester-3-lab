#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>

void dfs(int ** arr,int size,int index,int * visited){
    visited[index]=1;
    for(int i=0;i<size;i++){
        if(arr[index][i]==1 && visited[i]==0){
            dfs(arr,size,i,visited);
        }
    }
}

void connected(int ** arr,int size){
    int* visited=(int *)malloc(sizeof(int)*size);
    int count =0;
    for(int i=0;i<size;i++){
        visited[i]=0;
    }

    for(int i=0;i<size;i++){
        if(visited[i]==0){
            dfs(arr,size,i,visited);
            count++;
        }
    }
    printf("%d \n",count);
}


int main(){
    int n,e;
    scanf("%d %d",&n,&e);
    int** red=(int **)malloc(sizeof(int *)*n);
    int** green=(int **)malloc(sizeof(int *)*n);
    int** blue=(int **)malloc(sizeof(int *)*n);
    for(int i=0;i<n;i++){
        red[i]=(int *)malloc(sizeof(int)*n);
        green[i]=(int *)malloc(sizeof(int)*n);
        blue[i]=(int *)malloc(sizeof(int)*n);
        for(int j=0;j<n;j++){
            red[i][j]=0;
            green[i][j]=0;
            blue[i][j]=0;
        }
    }

    for(int K=0;K<n;K++){
        char line[256];
        fgets(line,sizeof(line),stdin);
        char * token=strtok(line," ");
        int i=atoi(token);
        int j;
        token=strtok(NULL," ");
        while(token!=NULL){
            if(strcmp(token,"R")==0){
                token=strtok(NULL," ");
                j=atoi(token);
                red[i-1][j-1]=1;
            }
             if(strcmp(token,"G")==0){
                token=strtok(NULL," ");
                j=atoi(token);
                green[i-1][j-1]=1;
            }
             if(strcmp(token,"B")==0){
                token=strtok(NULL," ");
                j=atoi(token);
                blue[i-1][j-1]=1;
            }
            token=strtok(NULL," ");
        }
    }

    connected(red,n);
    connected(green,n);
    connected(blue,n);

    return 0;
    }
