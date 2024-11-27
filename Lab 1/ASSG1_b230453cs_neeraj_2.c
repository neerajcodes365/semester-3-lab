#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int model_number;
    char name[1000];
    int price;
    struct node* left;
    struct node* right;
    struct node* parent;
};

struct node* create_node(int model, char name[], int price) {
    struct node* a = (struct node*)malloc(sizeof(struct node));
    a->model_number = model;
    strcpy(a->name, name);
    a->price = price;
    a->left = a->right = a->parent = NULL;
    return a;
}

struct node* add(struct node* root, int model, char name[], int price) {
    if (root == NULL) return create_node(model, name, price);
    if (root->model_number > model) {
        root->left = add(root->left, model, name, price);
        root->left->parent = root;
    } else {
        root->right = add(root->right, model, name, price);
        root->right->parent = root;
    }
    return root;
}

void modify(struct node* root, int model, int newprice) {
    while (root != NULL) {
        if (root->model_number == model) {
            root->price = newprice;
            printf("%d %s %d\n", root->model_number, root->name, root->price);
            return;
        }
        if (root->model_number > model) root = root->left;
        else root = root->right;
    }
    printf("-1\n");
}

void search(struct node* root, int model) {
    while (root != NULL) {
        if (root->model_number == model) {
            printf("%d %s %d\n", root->model_number, root->name, root->price);
            return;
        }
        if (root->model_number > model) root = root->left;
        else root = root->right;
    }
    printf("-1\n");
}

struct node* find_min(struct node* root) {
    while (root->left != NULL) root = root->left;
    return root;
}

struct node* delete(struct node* root, int model) {
    if (root == NULL) {
        printf("-1\n");
        return root;
    }
    if (root->model_number > model) {
        root->left = delete(root->left, model);
    } else if (root->model_number < model) {
        root->right = delete(root->right, model);
    } else {
        printf("%d %s %d\n", root->model_number, root->name, root->price);
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = find_min(root->right);
        root->model_number = temp->model_number;
        strcpy(root->name, temp->name);
        root->price = temp->price;
        root->right = delete(root->right, temp->model_number);
    }
    return root;
}

void postorder(struct node *root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d %s %d\n", root->model_number, root->name, root->price);
}

void preorder(struct node *root) {
    if (root == NULL) return;
    printf("%d %s %d\n", root->model_number, root->name, root->price);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node *root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d %s %d\n", root->model_number, root->name, root->price);
    inorder(root->right);
}

int main() {
    struct node *root = NULL;
    int model;
    char name[1000];
    int price;

    char choice;
    do {
        scanf(" %c", &choice);  
        switch (choice) {
            case 'a':
                scanf("%d", &model);
                scanf("%s", name);
                scanf("%d", &price);
                root = add(root, model, name, price);
                break;

            case 'd':
                scanf("%d", &model);
                root = delete(root, model);
                break;

            case 's':
                scanf("%d", &model);
                search(root, model);
                break;

            case 'i':
                inorder(root);
                break;

            case 'p':
                preorder(root);
                break;

            case 't':
                postorder(root);
                break;

            case 'm':
                scanf("%d", &model);
                scanf("%d", &price);
                modify(root, model, price);
                break;

            case 'e':
                break;
        }
    } while (choice != 'e');
    return 0;
}
