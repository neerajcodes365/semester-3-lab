#include<stdio.h>

struct node {
    int val;
    struct node * left;
    struct node * right;
    struct node * parent;
};

struct node * insert(struct node * root,int val){
    if(root==NULL) return createnode(val);
    if(root->val>val){
        root->left=insert(root->left,val);
        root->left->parent=root;
    }
    else(root->val<val){
        root->right=insert(root->right,val);
        root->right->parent=root;
    }
    return root;
}

struct node * delete(struct node * root,int val){
    if(root==NULL) return NULL;
    struct node * temp;
    if(root->val>val){
        root->left=delete(root->left,val);
        if(root->left!=NULL)root->left->parent=root;
    }
    if(root->val<val){
        root->right=delete(root->right,val);
        if(root->right!=NULL)root->right->parent=root;
    }
    if(root->left!=NULL && root->right==NULL){
        temp=root->left;
        temp->parent=root->parent;
        free(root);
        return temp;
    }
    if(root->right!=NULL && root->left==NULL){
        temp=root->right;
        temp->parent=root->parent;
        free(root);
        return temp;
    }
    if( root->right !=NULL && root->left != NULL){

        temp=findmin(root->right);
        root->val=temp->val;
        root->right=delete(root->right,temp->val);
        if(root->right!=NULL)root->right->parent=root;}

    return root;
    }












void zizzag(struct node * root){
    struct node * arr[10000];
    int front=0,rear=0;
    arr[rear++]=root;
    int flag=2;
    while(front<rear){
    int size=rear-front;
    int *zig=(int *)malloc(sizeof(int)*size);
    int index=0;
    while(size-->0){
            struct node * temp=arr[front++];
            zig[index++]=temp->val;
            if(temp->left) arr[rear++]=temp->left;
            if(temp->right) arr[rear++]=temp->right;
    }
    if(flag%2==0){
        for(int i=index;i>=0;i--){
            printf("%d ",zig[i]);
        }
        printf("\n");
    }
    if(flag%2==1){
        for(int i=0;i<=index;i++){
            printf("%d",zig[i]);
        }
        printf("\n");
    }
    flag++;
    free(zig);
    }
}











    