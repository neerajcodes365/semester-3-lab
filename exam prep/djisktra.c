void djisktra(int ** arr,int size,int ** w8arr,int src){
    int check[size];
    int dis[size];

    for(int i=0;i<size;i++){
        check[i]=0;
        dis[i]=INT_MAX;
    }

    dis[src]=0;


    for(int i=0;i<size;i++){
    int mindex=min(arr,check,size);
    check[mindex]=1;

        for(int j=0;j<size;j++){
            if(arr[mindex][j]==1 && !check[j] && dis[mindex]+w8arr[mindex][j]<dis[j]){
                dis[j]=dis[mindex]+w8arr[mindex][j];
            }
            }
        }

    }

    for(int i=0;i<size;i++){
        char line[256];
        fgets(line,sizeof(line),stdin);
        char *word=strtok(line," ");        
        int i=atoi(word);
        char *word=strtok(NULL," ");
        int count=0;
        while(word!=NULL){
            int j=atoi(word);
            int index=nm1(arr,i-1,count,size);
            w8arr[i-1][index]=j;
            count++;
            word=strtok(NULL," ");
        }


        }
    }


