#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* newNode(int val) {
    struct node *a = (struct node *)malloc(sizeof(struct node));
    a->data = val;
    a->left = NULL;
    a->right = NULL;
    return a;
}


int findIndex(int* arr, int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}


struct node* buildTreeHelper(int* preorder, int* inorder, int inorderStart, int inorderEnd, int* preorderIndex) {
    if (inorderStart > inorderEnd) {
        return NULL;
    }

    int rootValue = preorder[*preorderIndex];
    (*preorderIndex)++;

    struct node* root = newNode(rootValue);

    int inorderIndex = findIndex(inorder, inorderStart, inorderEnd, rootValue);

    root->left = buildTreeHelper(preorder, inorder, inorderStart, inorderIndex - 1, preorderIndex);
    root->right = buildTreeHelper(preorder, inorder, inorderIndex + 1, inorderEnd, preorderIndex);

    return root;
}

struct node* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    int preorderIndex = 0;                   //inorderstarts
    return buildTreeHelper(preorder, inorder, 0, inorderSize - 1, &preorderIndex);
}

void postorder(struct node *root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void sigsag(struct node * root){
    if(root==NULL) return;
    struct node **que=(struct node** )malloc(sizeof(struct node *));
    int front=0,rear=0;
    int level=0,size=1;
    que[rear++]=root;
    while(front<rear){
        int index=0;
        size=rear-front;
        int * array=(int*)malloc(size*sizeof(int));
        while(size-- >0){
            struct node* node=que[front++];
            array[index++]=node->data;
            if(node->left) que[rear++]=node->left;
            if(node->right) que[rear++]=node->right;
        }
        if(level%2==0){
            for(int i=0;i<index;i++) printf("%d",array[i]);
        }
        else{
            for(int i=index-1;i>=0;i--) printf("%d",array[i]);
        }
        level++;
        free(array);
    }
    free(que);
}


void level_order(struct node * root){
    if(root==NULL) return;
    srtuct node ** queue=(struct node **)malloc(1000*sizeof(struct node*));
    int rear=0,front=0;

    queue[rear++]=root;
    while(front<rear){
        struct node* node=queue[front++];
        printf("%d",node->data);
        if(node->left!= NULL) queue[rear++]=node->left;
        if(node->right!= NULL) queue[rear++]=node->right;
    }
    free(queue);
}

void zig_zag(struct node *root) {
    if (root == NULL) return;

    struct node **queue = (struct node **)malloc(1000 * sizeof(struct node *));
    int front = 0, rear = 0, level = 0, size = 1;

    queue[rear++] = root;

    while (front < rear) {
        int levelSize = rear - front;
        int *levelNodes = (int *)malloc(levelSize * sizeof(int));
        int index = 0;

        while (levelSize-- > 0) {
            struct node *node = queue[front++];

            levelNodes[index++] = node->data;

            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }

        if (level % 2 == 0) {
            for (int i = index - 1; i >= 0; i--) {
                printf("%d ", levelNodes[i]);
            }
        } else {
            for (int i = 0; i < index; i++) {
                printf("%d ", levelNodes[i]);
            }
        }

        free(levelNodes);
        level++;
    }

    printf("\n");
    free(queue);
}

void level_max(struct node *root) {
    if (root == NULL) return;

    struct node **queue = (struct node **)malloc(1000 * sizeof(struct node *));
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        int levelSize = rear - front;
        int maxVal = queue[front]->data;

        while (levelSize-- > 0) {
            struct node *node = queue[front++];

            if (node->data > maxVal) maxVal = node->data;

            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }

        printf("%d ", maxVal);
    }

    printf("\n");
    free(queue);
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
    return dia+1;
}

int right_leaf_sum(struct node * root){
    if(root==NULL) return 0;
    if(root->right!=NULL && root->right->right==NULL && root->right->left==NULL){
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

int main() {
    int size;
    scanf("%d", &size);
    if(size<1 || size>1000000) return 0;
    int inorder[size];
    for (int i = 0; i < size; i++) {
        scanf("%d", &inorder[i]);
    }

    int preorder[size];
    for (int i = 0; i < size; i++) {
        scanf("%d", &preorder[i]);
    }

    struct node *root = buildTree(preorder, size, inorder, size);

    char choice;

    do {
        scanf(" %c", &choice); 
        switch (choice) {
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
                printf("%d\n", diameter(root));
                break;
            case 's':
                printf("%d\n", right_leaf_sum(root));
                break;
            case 'e':
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 'e');

    return 0;
}
