#include<stdio.h>
#include<stdlib.h>

struct node {
    int val;
    struct node * next;
};

// struct node * createnode(int val){
//     struct node * a=(struct node *)malloc(sizeof(struct node));
//     a->val=val;
//     a->next=NULL;
//     return a;
// }

int hash(int key,int size){
    return key%size;
}

void insert(struct node ** arr,int val){
     struct node * a=(struct node *)malloc(sizeof(struct node));
    int index=hash(val,size);
    a->val=val;
    a->next=arr[index];
    // struct node * temp=arr[index];
    arr[index]=a;
    // arr[index]->next=temp;
}

int search(struct node * arr[],int key){
    int index=hash(key);
    if(arr[index]==NULL) printf("-1");
    struct node * temp=arr[index];
    int count=1;
    while(temp!=NULL){
        if(temp->val==key) return count;
        count++;
    }
    prinft("-1\n");
}

void delete(struct node * arr[],int val){
    int index=hash(val);
    
i know it ,
}

3rd question

















int main(){
int size;
scanf("%d",&size);
struct node * arr[size];
for(int i=0;i<size;i++){
    arr[i]=NULL;
}
int val,old,new,index;
char choice;
do{

    scanf("%c",&choice);
    switch(choice){
        case 'a':
        scanf("%d",&val);
        insert(arr,val);
        break;
        case 'b':
        scanf("%d",&val);
        search(arr,val);
        break;
        case 'c':
        scanf("%d",&val);
        delete(arr,val);
        break;
        case 'd':
        scanf("%d %d",&old,&new);
        update(arr,old,new);
        break;
        case 'e':
        scanf("%d",&index)
        print(arr,index);
        break;
        case 'f':
        break;
    }
}while(choice!='f');

return 0;
}