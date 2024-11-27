#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 1000

struct node
{
    int key;
    int height;
    struct node *left;
    struct node *right;
};

struct node *createNode(int key)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->key = key;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->height = 1;
    return new_node;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int getHeight(struct node *root)
{
    if (root == NULL)
        return 0;
    return root->height;
}

int getBalanceFactor(struct node *root)
{
    if (root == NULL)
        return 0;
    return getHeight(root->left) - getHeight(root->right);
}

struct node *rightRotate(struct node *y)
{
    struct node *x = y->left;
    struct node *t2 = x->right;

    x->right = y;
    y->left = t2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

struct node *leftRotate(struct node *x)
{
    struct node *y = x->right;
    struct node *t2 = y->left;

    x->right = t2;
    y->left = x;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

struct node *minValueNode(struct node *root)
{
    struct node *current = root;
    while (current->left != NULL)
        current = current->left;
    return current;
}

int search(struct node *root, int key)
{
    if (root == NULL)
        return 0;
    if (root->key == key)
        return 1;
    if (root->key > key)
        return search(root->left, key);
    else
        return search(root->right, key);
}
struct node* find(struct node *root, int key)
{
    if (root == NULL)
        return 0;
    if (root->key == key)
        return root;
    if (root->key > key)
        return find(root->left, key);
    else
        return find(root->right, key);
}
void preorder(struct node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->key);
    preorder(root->left);
    preorder(root->right);
}

struct node *maxValueNode(struct node *node) {
    struct node *current = node;
    while (current && current->right != NULL) {
        current = current->right;
    }
    return current;
}

void helpprintParenthesis(struct node *root)
{
    if (root == NULL)
    {   printf("( ) ");
        return;
    }
    printf("( %d ", root->key);
    if(root->left == NULL && root->right == NULL){
    printf(") ");
    return;
    } 
    helpprintParenthesis(root->left);
    helpprintParenthesis(root->right);
    printf(") ");
}

void printParenthesis(struct node * root){
    if(root == NULL) return;
    printf("%d ",root->key);
    helpprintParenthesis(root->left);
    helpprintParenthesis(root->right);
}


struct node *findInorderSuccessor(struct node *root, int key)
{
    struct node *current = root;
    struct node *successor = NULL;

    while (current != NULL)
    {
        if (key < current->key)
        {
            successor = current;
            current = current->left;
        }
        else if (key > current->key)
        {
            current = current->right;
        }
        else
        {
            if (current->right != NULL)
            {
                successor = minValueNode(current->right);
            }
            break;
        }
    }
    return successor;
}

struct node *findInorderPredecessor(struct node *root, int key)
{
    struct node *current = root;
    struct node *predecessor = NULL;

    while (current != NULL)
    {
        if (key > current->key)
        {
            predecessor = current;  // The current node could be the predecessor
            current = current->right;
        }
        else if (key < current->key)
        {
            current = current->left;
        }
        else
        {
            if (current->left != NULL)
            {
                predecessor = maxValueNode(current->left);  // Find the max in the left subtree
            }
            break;
        }
    }
    return predecessor;
}


int convert(char *str, int *index)
{
    int val = 0;
    while (isdigit(str[*index]))
    {
        val *= 10;
        val += (str[*index] - '0');
        (*index)++;
    }
    if (str[*index] == ' ')
        (*index)++;
    return val;
}

struct node *build(char *str, int *index)
{
    if (str[*index] == '(')
        (*index) += 2;

    if (str[*index] == ')')
    {
        (*index) += 2;
        return NULL;
    }

    int val = convert(str, index);
    struct node *z = createNode(val);

    if (str[*index] == ')')
    {
        (*index) += 2;
        return z;
    }

    z->left = build(str, index);
    z->right = build(str, index);

    if (str[*index] == ')')
    {
        (*index) += 2;
    }
    return z;
}

struct node *buildTree(char *str, int *index)
{
    int rootval = convert(str, index);
    struct node *h = createNode(rootval);

    h->left = build(str, index);
    h->right = build(str, index);

    return h;
}

struct node *insert(struct node *root, int key)
{
    if (root == NULL)
        return createNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else
        return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int bf = getBalanceFactor(root);

    if (bf > 1 && key < root->left->key)
        return rightRotate(root);

    if (bf < -1 && key > root->right->key)
        return leftRotate(root);

    if (bf > 1 && key > root->left->key)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (bf < -1 && key < root->right->key)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

struct node *deleteNode(struct node *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == NULL || root->right == NULL)
        {
            struct node *temp = root->left ? root->left : root->right;
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
            {
                *root = *temp;
            }
            free(temp);
        }
        else
        {
            struct node *temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int bf = getBalanceFactor(root);

    if (bf > 1 && getBalanceFactor(root->left) >= 0)
        return rightRotate(root);

    if (bf > 1 && getBalanceFactor(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (bf < -1 && getBalanceFactor(root->right) <= 0)
        return leftRotate(root);

    if (bf < -1 && getBalanceFactor(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

struct node *avl_rangedelete(struct node *root, int n1, int n2)
{
    int find = 0;
    for (int i = n1; i <= n2; i++)
    {
        if (search(root, i))
        {
            find++;
            root = deleteNode(root, i);
        }
    }
    printf("%d ", find);
    preorder(root);
    return root;
}

void avl_successorpath(struct node *root, int n)
{
    struct node *successor = findInorderSuccessor(root, n);
    if (successor)
    {
        while (root)
        {
            printf("%d ", root->key);
            if (root->key > successor->key)
                root = root->left;
            else if (root->key < successor->key)
                root = root->right;
            else
                break;
        }
        printf("\n");
    }
    else
    {
        printf("%d\n", getHeight(root)-1);
    }
}
int helpsubsum(struct node * root){
    if (root == NULL)
        return 0;
    return root->key + helpsubsum(root->left) + helpsubsum(root->right);
}
int subsum(struct node *root,int key) {
    if(!search(root,key)) return -1;
   else{
   return helpsubsum(find(root,key));
   }
}


int findClosest(struct node *root, int target) {
    if (root == NULL) return -1;
    if(!search(root,target)) return -1;
    struct node *successor = findInorderSuccessor(root, target);
    struct node *predecessor = findInorderPredecessor(root, target);
    int diffSuccessor;
    int diffPredecessor;
    int closest = -1;
    
    if(successor!=NULL){
        diffSuccessor=abs(successor->key - target);
    }
    if(predecessor!=NULL){
        diffPredecessor= abs(predecessor->key - target);
    }
    if (diffSuccessor < diffPredecessor) {
        closest = successor->key;
    } else {
        closest = predecessor->key;
    }
    
    return closest;
}


void inorder(struct node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}

int main()
{
    char choice;
    int n, n1, n2,key;
    char string[MAX];
    struct node *root = NULL;

    fgets(string, MAX, stdin);
    int idx = 0;
    root = buildTree(string, &idx);

    do
    {
        scanf(" %c", &choice);
        switch (choice)
        {
        case 'a':

            while (1)
            {
                int num;
                char ch;
                scanf("%c", &ch);
                if (ch == '\n')
                    break;

                scanf("%d", &num);
                root = insert(root, num);
            }

            printParenthesis(root);
            printf("\n");
            break;

        case 'b':
            scanf("%d %d", &n1, &n2);
            root = avl_rangedelete(root, n1, n2);
            printf("\n");
            break;
        case 'c':
            scanf("%d", &n);
            avl_successorpath(root, n);
            break;
        case 'd':
            scanf("%d",&key);
            printf("%d ", subsum(root,key));
            if(subsum(root,key)!=-1){
            printParenthesis(find(root,key));
            }
            printf("\n");
            break;
        case 'e':
            scanf("%d", &n);
            printf("%d\n", findClosest(root, n));

            break;
        case 'f':
            preorder(root);
            printf("\n");
            break;
        case 'i':
            inorder(root);
            printf("\n");
            break;
        case 'g':
            break;
        }
    } while (choice != 'g');
    return 0;
}
