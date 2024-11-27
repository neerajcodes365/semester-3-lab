#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    int value;
    int height;
    struct node* left;
    struct node* right;
};

struct node* createNode(int key, int value) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->key = key;
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

int getHeight(struct node* root) {
    if (root == NULL) return 0;
    return root->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int balanceFactor(struct node* root) {
    if (root == NULL) return 0;
    return getHeight(root->left) - getHeight(root->right);
}

struct node* rightRotate(struct node* y) {
    struct node* x = y->left;
    struct node* t2 = x->right;

    x->right = y;
    y->left = t2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

struct node* leftRotate(struct node* x) {
    struct node* y = x->right;
    struct node* t2 = y->left;

    x->right = t2;
    y->left = x;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

struct node* insert(struct node* root, int key, int value) {
    if (root == NULL) return createNode(key, value);

    if (key < root->key) {
        root->left = insert(root->left, key, value);
    } else if (key > root->key) {
        root->right = insert(root->right, key, value);
    } else {
        // If the key is already present, update its value
        root->value = value;
        return root;
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

void find(struct node* root, int key) {
    if (root == NULL) {
        printf("-1\n");
        return;
    }
    if (root->key == key) {
        printf("%d %d\n", root->key, root->value);
        return;
    }
    if (root->key > key) {
        find(root->left, key);
    } else {
        find(root->right, key);
    }
}

struct node* upperfind(struct node* root, int key) {
    struct node* result = NULL;
    while (root != NULL) {
        if (root->key >= key) {
            result = root;
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return result;
}

void upperbound(struct node* root, int key) {
    struct node* result = upperfind(root, key);
    if (result != NULL) {
        printf("%d %d\n", result->key, result->value);
    } else {
        printf("-1\n");
    }
}

int size(struct node* root) {
    if (root == NULL) return 0;
    return 1 + size(root->left) + size(root->right);
}

void empty(struct node* root) {
    if (size(root) == 0)
        printf("1\n");
    else
        printf("0\n");
}

void reverseInOrder(struct node* root) {
    if (root == NULL) return;
    reverseInOrder(root->right);
    printf("%d ", root->key);
    reverseInOrder(root->left);
}

void displayelements(struct node* root) {
    if (root == NULL) {
        printf("-1\n");
        return;
    }
    reverseInOrder(root);
    printf("\n");
}

int main() {
    int key, value, tsize;
    struct node* root = NULL;
    char choice;
    do {
        scanf(" %c", &choice);
        switch (choice) {
            case 'i':
                scanf("%d %d", &key, &value);
                root = insert(root, key, value);
                break;

            case 'u':
                scanf("%d", &key);
                upperbound(root, key);
                break;

            case 'f':
                scanf("%d", &key);
                find(root, key);
                break;

            case 's':
                tsize = size(root);
                printf("%d\n", tsize);
                break;

            case 'e':
                empty(root);
                break;

            case 'd':
                displayelements(root);
                break;
        }
    } while (choice != 't');

    return 0;
}
