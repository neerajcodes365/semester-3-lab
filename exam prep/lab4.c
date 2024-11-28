#include<stdio.h>
#include<stdlib.h>

struct node{
    int val;
    struct node * left;
    struct node * right;
    int height;
};

struct node* createnode(int val){
    struct node * a=(struct node *)malloc(sizeof(struct node));
    a->height=1;
    a->left=NULL;
    a->right=NULL;
    a->val=val;
    return a;
}

int getheight(struct node * root){
if(root==NULL)return 0;
else return root->height;
}

int balancefactor(struct node * root){
    if(root==NULL)return 0;
    else{
        return getheight(root->left) - getheight(root->right);
    }
}
int max(int a,int b){
    return (a>b)?a:b;
}

struct node * insert(struct node * root,int val){

    if(root==NULL) return createnode(val);
    if(root->val>val){
        root->left=insert(root->left,val);
    }
    else if (root->val<val){
        root->right=insert(root->right,val);
    }
    root->height= max(getheight(root->left),getheight(root->right))+1;
    int bf=balancefactor(root);
    // ll
    if(bf>1 && root->left->val>val){
        return rtrotate(root);
    }
    //lr
    if(bf>1 && root->left->val<val){
         root->left=ltrotate(root->left);
        return rtrotate(root);
    }
//rr
    if(bf<-1 && root->right->val<val){
        return ltrotate(root);
    }
    //rl
    if(bf<-1 && root->right->val>val){
         root->right=rtrotate(root->right);
        return ltrotate(root);
    }
return root;

}

struct node * rtrotate(struct node * x){

struct node * y=x->left;
struct node * t2=y->right;

y->right=x;
x->left=t2;

x->height=max(getheight(x->left),getheight(x->right))+1;
y->height=max(getheight(y->left),getheight(y->right))+1;

return y;

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
    if(root==NULL) return;

    root->height= max(getheight(root->left),getheight(root->right))+1;
    int bf=balancefactor(root);
    // ll
    if(bf>1 && bf(root->left)>=0){
        return rtrotate(root);
    }
    //lr
    if(bf>1 && bf(root->left)<0){
         root->left=ltrotate(root->left);
        return rt(root);
    }
    //rr
    if(bf<-1 && balancefactor(root->right)<0){
        return ltrotate(root);
    }
    //rl
    if(bf<-1 && bf(root->right)>=0){
         root->right=rtrotate(root->right);
        return ltrotate(root);
    }
return root;


}

int search(struct node *root, int key){
    if(root==NULL) return 0;
    if(root->val==key) return 1;
    if(root->val>key) return search(root->left,key);
    if(root->val<key) return search(root->right,key);
}


void collectnodes(struct node *root,struct node **arr,int *index){
    if(root==NULL) return;
    if(root!=NULL){
        arr[(*index)]=root;
        (*index)++;
    }
    collectnodes(root->left,arr,index);
    collectnodes(root->right,arr,index);
}

void collectexample(struct node * root){
    struct node * arr[10000];
    int index=0;
    collectnodes(root,arr,&index);
}










int main() {
    int n;
    struct node* root = NULL;
    char choice;
    do {
        scanf(" %c", &choice);  
        switch (choice) {
            case 'i':
                scanf("%d", &n);
                root = avlInsert(root, n);
                break;
            case 'f':
                scanf("%d", &n);
                avlFind(root, n);
                break;
            case 'p':
                postorder(root);
                printf("\n");
                break;
            case 's':
                avlRotation(root);
                break;
            case 'd':
                scanf("%d", &n);
                root = avlDelete(root, n);
                printf("\n");
                break;
            case 'b':
                scanf("%d", &n);
                avlBalanceFactor(root, n);
                break;
        }
    } while (choice != 'e');
    return 0;
}
