// void helpdepth(struct node * root,struct node *tofind,int *dp){

//     if(root==NULL)return ;

//     if(root==tofind){
//         return;
//     }
//     (*dp)++;
//     helpdepth(root->left,tofind,dp);
//     helpdepth(root->right,tofind,dp);
// }

void helpdepth(struct node * root,struct node *tofind,int *dp){

    if(root==NULL)return;
    if(root->left==tofind || root->right==tofind){
        return;
    }
    (*dp)++;
    helpdepth(root->left,tofind,dp);
    helpdepth(root->right,tofind,dp);

}



int depth(struct node * root,struct node *tofind){
    int dp=0;
    if(root==tofind) return dp;
    helpdepth(root,tofind,&tofind);
}