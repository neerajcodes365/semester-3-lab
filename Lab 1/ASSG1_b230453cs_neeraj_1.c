#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * left;
    struct node * right;
};

struct node * newNode(int val ){
    struct node *a=(struct node *)malloc(sizeof(struct node));
    a->data=val;
    a->left=NULL;
    a->right=NULL;
    return a;
}
struct que{
    struct node * q_node;
    struct que* next;
};

struct que* queNode(struct node* b){
    struct que *c=(struct que *)malloc(sizeof(struct que));
    c->q_node=b;
    c->next=NULL;
    return c;
}

struct que * push(struct node * root,struct que *q_node){
  
 


}

int findIndex(int* arr, int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}


struct TreeNode* buildTreeHelper(int* preorder, int* inorder, int inorderStart, int inorderEnd, int* preorderIndex) {

    if (inorderStart > inorderEnd) {
        return NULL;
    }

    int rootValue = preorder[*preorderIndex];
    (*preorderIndex)++;

    struct TreeNode* root = newNode(rootValue);

    int inorderIndex = findIndex(inorder, inorderStart, inorderEnd, rootValue);
   
    root->left = buildTreeHelper(preorder, inorder, inorderStart, inorderIndex - 1, preorderIndex);
    root->right = buildTreeHelper(preorder, inorder, inorderIndex + 1, inorderEnd, preorderIndex);

    return root;
}


struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    int preorderIndex = 0;
    return buildTreeHelper(preorder, inorder, 0, inorderSize - 1, &preorderIndex);
}

void postorder(struct node *root){
    postorder(root->left);
    postorder(root->right);
    printf("%d ",&root->data);
}

struct linkedlist{
    int data;
    struct linkedlist * next;
};



void zig_zag(struct node * root){
 if( root==NULL) return;
 struct que * q =NULL;
 q=que_push(q,root);
}

int getdiameter(struct node* root, int* dia) {
    if (root == NULL) return 0;

    int lh = getdiameter(root->left, dia);
    int rh = getdiameter(root->right, dia);


    if (lh + rh > *dia) {
        *dia = lh + rh;
    }

  
    return 1 + (lh > rh ? lh : rh);
}

int diameter(struct node* root) {
    int dia = 0;
    getdiameter(root, &dia);
    return dia;
}

int right_leaf_sum(struct node * root){
    if(root==NULL) return 0;
    if(root->right!==NULL && root->right->right==NULL && root->right->left==NULL){
        if(root->left==NULL){
            return root->right->data;
        }
        else{
            return root->right->data + right_leaf_sum(root->left);
        }
    }
    int x=right_leaf_sum(root->left);
    int y=right_leaf_sum(root->right);
    return x+y;
}

int main(){
int right_sum;
int dia;
int size;
scanf("%d",&size);

int inorder[size];
for(int i=0;i<size;i++){
    scanf("%d",&inorder[i]);
}


int preorder[size];
for(int i=0;i<size;i++){
    scanf("%d",&preorder[i]);
}

struct node *root = buildTree(preorder, size, inorder, size);

char choice;


do{
    scanf("%c",&choice);
    switch(choice){
        case 'p':
        postorder(root);
        printf("\n");
        break;
        case 'z':
        zig_zag(root);
        break;
        case 'm':
        level_max(root);
        break;
        case 'd':
        dia=diameter(root);
        printf("%d\n",&dia);
        break;
        case 's':
        right_sum=right_leaf_sum(root);
        printf("%d",&right_sum);
        break;
        case 'e':
        break;
    }
}while(choice!='e');

return 0;
}