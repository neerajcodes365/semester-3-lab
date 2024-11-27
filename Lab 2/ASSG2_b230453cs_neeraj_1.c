#include <stdio.h>
#include <stdlib.h>


struct node {
    int key;
    int height;
    struct node* left;
    struct node* right;
};

int left_rotations = 0;
int right_rotations = 0;

struct node* createNode(int key) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;  
    return node;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int getHeight(struct node* root) {
    if (root == NULL) return 0;
    return root->height;
}

int balanceFactor(struct node* root) {
    if (root == NULL) return 0;
    return getHeight(root->left) - getHeight(root->right);
}
int search(struct node* root, int key) {
    if (root == NULL) return 0;  
    if (root->key == key) return 1;  
    if (root->key > key) {
        return search(root->left, key); 
    } else {
        return search(root->right, key);  
    }
}


struct node* rightRotate(struct node* y) {
    if (y == NULL || y->left == NULL) return y;
    struct node* x = y->left;
    struct node* t2 = x->right;

    x->right = y;
    y->left = t2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    right_rotations++;  

    return x;
}

struct node* leftRotate(struct node* x) {
    if (x == NULL || x->right == NULL) return x;
    struct node* y = x->right;
    struct node* t2 = y->left;

    x->right = t2;
    y->left = x;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    left_rotations++;  

    return y;
}

struct node* avlInsert(struct node* root, int key) {
    if (root == NULL) return createNode(key);

    if (key < root->key) {
        root->left = avlInsert(root->left, key);
    } else if (key > root->key) {
        root->right = avlInsert(root->right, key);
    }

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int bf = balanceFactor(root);

    // Left Left Case
    if (bf > 1 && key < root->left->key) {
        return rightRotate(root);
    }

    // Right Right Case
    if (bf < -1 && key > root->right->key) {
        return leftRotate(root);
    }

    // Left Right Case
    if (bf > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left Case
    if (bf < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void printDelSearch(struct node* root, int key) {
    if (root == NULL) return;  
    
    // Traverse to the left or right child before printing
    if (root->key > key) {
        printDelSearch(root->left, key); 
    } else if (root->key < key) {
        printDelSearch(root->right, key);  
    }

    // Print the current key after traversing to the correct child
    printf("%d ", root->key);
}


struct node* minValueNode(struct node* node) {
    struct node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

struct node* deleteNode(struct node* root, int key) {
    if (root == NULL) return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL || root->right == NULL) {
            struct node* temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else {
                *root = *temp;
            }
            free(temp);
        } else {
            struct node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == NULL) return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int bf = balanceFactor(root);

    // Left Left Case
    if (bf > 1 && balanceFactor(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (bf > 1 && balanceFactor(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (bf < -1 && balanceFactor(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (bf < -1 && balanceFactor(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

struct node* avlDelete(struct node* root, int key) {
    if (root == NULL) return root;

    // If the key is found, print ancestors and proceed with deletion
    if (search(root, key)) {
        printDelSearch(root, key);
        root = deleteNode(root, key);  // Use the standard deletion logic
        printf("\n");  // Ensure a newline after printing the path
    } else {
        printf("-1\n");  // Print -1 if the key is not found
    }
    return root;
}

void avlBalanceFactor(struct node* root, int key) {
    while (root != NULL) {
        if (root->key == key) {
            printf("%d\n", balanceFactor(root));
            return;
        }
        if (root->key > key) root = root->left;
        else root = root->right;
    }
    printf("-1\n");
}


void printSearch(struct node* root, int key) {
    if (root == NULL) return;  
    printf("%d ", root->key);
    if (root->key > key) {
        printSearch(root->left, key); 
    } else if (root->key < key) {
        printSearch(root->right, key);  
    }
}

void avlFind(struct node* root, int key) {
    if (search(root, key)) {
        printSearch(root, key);
    } else {
        printf("-1");
    }
    printf("\n");
}

void avlRotation(struct node* root) {
    printf("%d %d\n", left_rotations, right_rotations);
}

void postorder(struct node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->key);
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
