#include<stdio.h>
#include<stdlib.h>

struct node {
    int val;
    struct node* left;
    struct node * right; 
};

struct node * createnode(int val){
    struct node * a=(struct node *)malloc(sizeof(struct node));
    a->val=val;
    a->left=a->right=NULL;
    return a;
}

struct node *insert(struct node* root,int val){
    if(root==NULL){
        return createnode(val);
    }
    if(root->val>val){
        root->left=insert(root->left,val);
    }
    if(root->val<val){
        root->right=insert(root->right,val);
    }
    return root;
}

struct node * succesor(struct node * root,int val){
    struct node * temp=NULL;

   while(root!=NULL){
    if(root->val>val){
        temp=root;
        root=root->left;
    }
    else root=root->right;
    }
    return temp;
}

int rightleafsum(struct node * root){
    if(root==NULL) return 0;
    if(root->right!=NULL && root->right->right==NULL && root->right->left==NULL){
        if(root->left!=NULL)return root->right->val+rightleafsum(root->left);
        else return root->right->val;
    }
    int a=rightleafsum(root->left);
    int b=rightleafsum(root->right);
    return a+b;
}
void collectNodes(struct node* root, struct node** nodesArray, int* index) {
    if (root == NULL) return;
    nodesArray[*index] = root;
    (*index)++;
    collectNodes(root->left, nodesArray, index);
    collectNodes(root->right, nodesArray, index);
}

// Function to find the diameter of the tree
int diameter(struct node* root) {
    if (root == NULL) return 0;

    // Collect all nodes in an array
    struct node* nodesArray[1000]; // Adjust size as needed
    int index = 0;
    collectNodes(root, nodesArray, &index);

    // Compute the height for each node and determine the diameter
    int maxDiameter = 0;
    for (int i = 0; i < index; i++) {
        struct node* node = nodesArray[i];
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        int nodeDiameter = leftHeight + rightHeight + 2;
        if (nodeDiameter > maxDiameter) {
            maxDiameter = nodeDiameter;
        }
    }

    return maxDiameter;
}

struct node * predecisor(struct node * root,int val){
    struct node * temp=NULL;

   while(root!=NULL){
    if(root->val<val){
        temp=root;
        root=root->right;
    }
    else root=root->left;
    }
    return temp;
}

void parenthisis(struct node* root){
    if(root==NULL) {
        // printf("()");
        return;
    }
    printf("%d ",root->val);
    parenthisis(root->left);
    printf(" ) (");
    parenthisis(root->right);
    printf(")");
}
//  1(2(4)())(3)

int min(struct node* root){
    struct node * temp=root;
    struct node * prv=NULL;

    while(temp!=NULL){
        prv=temp;
        temp=temp->left;
    }
    return prv->val;

}

struct node * delete(struct node * root,int val){
    struct node *temp;
    if(root->val>val) root->left=delete(root->left,val);

    if(root->val<val) root->right=delete(root->right,val);

    if(root->left ==NULL && root->right==NULL){
        temp=root;
        free(temp);
        return NULL;
    }
    else if(root->left!=NULL && root->right==NULL){
        temp=root->left;
        free(root);
        return temp;
    }
    else if(root->left==NULL && root->right!=NULL){
        temp=root->right;
        free(root);
        return temp;
    }
    else if(root->left!=NULL && root->right!=NULL){
        int a=min(root->right);
        root->val=a;
        root->right=delete(root->right,a);
    }

    return root;

}

int main(){

    struct node * root=NULL;
    root=insert(root,1);
    root=insert(root,2);
    root=insert(root,3);
    root=insert(root,4);
    root=insert(root,5);
    struct node * i=succesor(root,3);
    if(i==NULL)printf("no succesor found\n");
    else printf("%d \n",i->val);
     i=predecisor(root,5);
    if(i==NULL)printf("no predecisor found\n");
    else printf("%d \n",i->val);
    parenthisis(root);
return 0;
}

