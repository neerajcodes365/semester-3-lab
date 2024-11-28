#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b){
int temp=*a;
*a=*b;
*b=temp;
}


void heapifyup(int heap[],int index){
    int parent=(index-1)/2;
    if(index>0 && heap[parent]<heap[index]){
        swap(&heap[parent],&heap[index]);
        heapifyup(arr,parent);
    }
}

void heapifydown(int heap[],int size,int index){
    int large=index;
    int left=index*2+1;
    int right=index*2+2;
    if(left<size && heap[left]>heap[large]){
        large=left;
    }
    if(right<size && heap[right]>heap[large]){
        large=right;
    }
    if(large!=index){
        swap(&heap[large],&heap[index]);
        heapifydown(arr,size,large);
    }
}

void insert(int arr[],int*heapsize,int val){
    arr[(*heapsize)]=val;
    (*heapsize)++;
    heapifyup(arr,(*heapifyup)-1);
}
int findmax(int arr[],int heapsize){
    if(heapsize!=0) return arr[0];
    else 0;
}
void deletekey(int arr[],int x,int *heapsize){
    int temp;
    for(int i=0;i<(*heapsize);i++){
        if(arr[i]==x)temp=i;
    }
    int temp2=arr[i];
    int temp3=arr[(*heapsize)-1];
    swap(&heap[temp],&heap[(*heapsize)-1]);
    (*heapsize)--;
    if(temp2>temp3) heapifydown(heap,(*heapsize),temp);
    else heapifyup(heap,temp);
}

void extractmin(int arr[],int *heapsize){
    if((*heapsize)!=0){
        int temp =arr[0];
       int temp3=arr[(*heapsize)-1];
    swap(&heap[0],&heap[(*heapsize)-1]);
    (*heapsize)--;
    heapifydown(heap,(*heapsize),0);
    }
}





int main()
{
    int maxsize = 100;
    int heap[maxsize];
    char choice;
    int heapsize = 0;
    int key, kthelement, oldval, newval;

    do
    {
        scanf(" %c", &choice);
        switch (choice)
        {
        case 'a':
            scanf("%d", &key);
            insert(heap, &heapsize, key);
            break;
        case 'b':
            printf("%d\n", findmax(heap, heapsize));
            break;
        case 'c':
            extractmax(heap, &heapsize);
            break;
        case 'd':
            scanf("%d", &kthelement);
            kthlargest(heap, kthelement, heapsize);
            break;
        case 'e':
            scanf("%d", &key);
            deletekey(heap, &heapsize, key);
            break;
        case 'f':
            scanf("%d %d", &oldval, &newval);
            replacekey(heap, heapsize, oldval, newval);
            break;
        case 'g':
            break;
        }
    } while (choice != 'g');

    return 0;
}





int helpdepth(struct node * root,struct node *tofind,int count){
    if(root==NULL) return -1;
    if(root==tofind) return count;

    count++;

    int x=helpdepth(root->left,tofind,count);
    int y=helpdepth(root->right,tofind,count);

    return max(x,y);
   
}
int depth(struct node * root,struct node * tofind){
    return helpdepth(root,tofind,0);
}

int height(struct node * root){
    
    if(root==NULL) return -1;

    int lt=height(root->left);
    int rt=height(root->right);

    return max(lt,rt)+1;
}

struct node * parent(struct node * root,struct node * tofind){


}

int leafsumnodes(struct node * root){
    if(root==NULL)return 0;
    if(root->left==NULL && root-> right==NULL) return root->val;
    int lt=leafsumnodes(root->left);
    int rt=leafsumnodes(root->right);
    return lt+rt;
}

int rightleafnodes(struct node* root){
    if(root==NULL) return 0;
    if(root->right!=NULL && root->right->right==NULL && root->right->left==NULL){
        if(root->left) return root->right->val+ rightleafnodes(root->left);
        else root->right->val;
    }
    int lef=rightleafnodes(root->left);
    int rt=rightleafnodes(root->right);
    return rt+lef;
}




