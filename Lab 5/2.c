#include<stdio.h>
#include<stdlib.h>
/*void BFS(int **graph, int startVertex, int *visited, int size) {
    int *queue = (int *)malloc(size * sizeof(int));    // Queue for BFS
    int front = 0, rear = -1;

    // Enqueue the starting vertex and mark it as visited
    rear++;
    queue[rear] = startVertex;
    visited[startVertex] = 1;

    printf("BFS starting from vertex %d: ", startVertex);

    while (front <= rear) {
        int currentVertex = queue[front++];  // Dequeue a vertex
        printf("%d ", currentVertex);        // Print the vertex being visited

        // Visit all adjacent vertices
        for (int i = 0; i < size; i++) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                rear++;
                queue[rear] = i;     // Enqueue the adjacent vertex
                visited[i] = 1;      // Mark it as visited
            }
        }
    }
    printf("\n");

    // Free dynamically allocated memory for the queue
    free(queue);
}

void BFS_Disconnected(int **graph, int size) {
    int *visited = (int *)malloc(size * sizeof(int));

    // Initialize all vertices as not visited
    for (int i = 0; i < size; i++) {
        visited[i] = 0;
    }

    // Apply BFS on each unvisited component
    for (int i = 0; i < size; i++) {
        if (!visited[i]) {
            BFS(graph, i, visited, size);  // Perform BFS for each disconnected component
        }
    }

    // Free dynamically allocated memory for the visited array
    free(visited);
}
*/
/*void bfs(int **arr,int size){
    int visited[size]={0};
    int que[size];
    int front=0,rear=-1;
    rear++;
    int startvertex=0;
    que[rear]=startvertex;
    visited[startvertex]=1;
    while (front<=rear)
    {
        int val=que[front++];
        for(int i=0;i<size;i++){
            if(arr[val][i]==1 && visited[i]==0){
                rear++;
                que[rear]=i;
                visited[i]=1;
            }
        }
    }
}
*/

int hascycle(int **arr,int size){
    int visited[size];
    int parent[size];
    for (int i = 0; i < size; i++) {
        visited[i] = 0;
        parent[i] = -1; 
    }
    int que[size];
    int front=0,rear=-1;
    rear++;
    int startvertex=0;
    que[rear]=startvertex;
    visited[startvertex]=1;
    parent[startvertex]=-1;

    while (front<=rear)
    {
        int val=que[front++];
        for(int i=0;i<size;i++){
            if(arr[val][i]==1){
                if(visited[i]==0){
                    rear++;
                    que[rear]=i;
                    visited[i]=1;
                    parent[i]=val;
                }
                else if(visited[i]==1 && parent[val]!=i) return 1;
            }
        }
    }
    return 0;
}
int isbipartate(int ** arr,int size){
   int coloured[size];
   for(int i =0;i<size;i++){
    coloured[i]=-1;
   }
   int que[size];  
   int rear=-1,front=0;

   int startvertex=0;

   rear++;
   coloured[startvertex]=0;
   que[rear]=startvertex;
   while(front<=rear){
    int val=que[front++];

    for(int i=0;i<size;i++){
        if(arr[val][i]==1){
            if(coloured[i]==-1){
                //colour
                if(coloured[val]==1) coloured[i]=0;
                else coloured[i]=1;
            }
            else if(coloured[i]!=-1){
                if(coloured[i]==coloured[val]) return 1;
            }
        }
    }
   }
   return 0;
}

/*int isConnected(int **arr, int size) {
    for (int i = 0; i < size; i++) {
        int count=0;
        for(int j=0;j<size;j++){
            if (arr[i][j]==0){
                count++;
            } 
            if(count==size)return 0;
        }    
    }
    return 1;
}*/

int isconnected(int **arr, int size) {
    int visited[size];
    int que[size];
    int front = 0, rear = -1;

    for (int i = 0; i < size; i++) {
        visited[i] = 0;
    }

    int startVertex = 0;
    rear++;
    que[rear] = startVertex;
    visited[startVertex] = 1;

    while (front <= rear) {
        int val = que[front++];  
        for (int i = 0; i < size; i++) {
            if (arr[val][i] == 1 && visited[i] == 0) {
                rear++;
                que[rear] = i;
                visited[i] = 1;
            }
        }
    }

    for (int i = 0; i < size; i++) {
        if (visited[i] == 0) {
            return 0;  
        }
    }

    return 1;  
}
      
int istree(int **arr,int size){
    int a=hascycle(arr,size);
    int b=isconnected(arr,size);
    if(a==0 && b==1) return 1;
    else return 0;
}


int main(){
    int n;
    int result;
    scanf("%d",&n);
    //int arr[n][n];
    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        arr[i] = (int *)malloc(n * sizeof(int));
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    char choice;

    do{
        scanf("%c",&choice);
        switch (choice)
        {
        case 'a':
        result=isbipartate(arr,n);
        if(result==1)printf("1\n");
        else printf("-1\n");
        break;

        case 'b':
        result=hascycle(arr,n);
        if(result==1)printf("1\n");
        else printf("-1\n");
        break;

        case 'c':
        result=istree(arr,n);
        if(result==1)printf("1\n");
        else printf("-1\n");
        break;
        
        case 'x':
            break;
        }
    }while(choice!='x');
return 0;
}