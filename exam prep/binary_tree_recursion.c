/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int height(struct TreeNode * root){
    if(root==NULL) return -1;
    int left=height(root->left);
    int right=height(root->right);
    return fmax(left,right)+1;
}

struct TreeNode* search(struct TreeNode * root,int x) {
    if(root==NULL) return NULL;
    if(root->val==x) return root;
    struct TreeNode * temp1=search(root->left,x);
    if(temp1==NULL) {
        return search(root->right,x);
    }
    return temp1;
}
int depth(struct TreeNode *root, struct TreeNode *node) {
    if (root == NULL) return -1;  
    if (root == node) return 0;   

    int left_depth = depth(root->left, node);
    int right_depth = depth(root->right, node);

    if (left_depth != -1) return left_depth + 1; 
    if (right_depth != -1) return right_depth + 1; 
    
    return -1; 
}



struct TreeNode* parent(struct TreeNode * root,struct TreeNode * temp) {
    if(root==NULL) return NULL;
    if(root->left==temp || root->right==temp) return root;
    struct TreeNode* temp1=parent(root->left,temp);
        if(temp1==NULL) return parent(root->right,temp);
        return temp1;
}

bool isCousins(struct TreeNode* root, int x, int y) {
    struct TreeNode* temp1=search(root,x);
    struct TreeNode* temp2=search(root,y);

    // if(height(temp1)==height(temp2)){
    //     if(parent(root,temp1)!=parent(root,temp2)) return true;
    // }
    // return false;
    int a=depth(root,temp1);
    int b=depth(root,temp2);
        if(a==b){
        if(parent(root,temp1)!=parent(root,temp2)) return true;
    }
    return false;
}