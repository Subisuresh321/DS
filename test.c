#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *newnode,*root=NULL,*parent=NULL;

void inorderDis(struct node *root);
struct node* insertEle(struct node *root,struct node *newnode);
void insert();
void delete();
struct node* findSucc(struct node *root);
struct node* deleteEle(struct node *root,int x);

void create(){
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        insert();
    }
    inorderDis(root);    
}

void insert(){
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d",&newnode->data);
    newnode->left=NULL;
    newnode->right=NULL;
    root=insertEle(root,newnode);
}

struct node* insertEle(struct node *root,struct node *newnode){
    if(root==NULL){
        root=newnode;
    }
    else if(root->data>newnode->data){
        root->left=insertEle(root->left,newnode);
    }
    else{
        root->right=insertEle(root->right,newnode);
    }
    return root;
}

void inorderDis(struct node *root){
    if(root ==NULL)
    return;
    inorderDis(root->left);
    printf("%d->",root->data);
    inorderDis(root->right);
}

void preorderDis(struct node *root){
    if(root ==NULL)
    return;
    printf("%d->",root->data);
    preorderDis(root->left);
    preorderDis(root->right);
}
void postorderDis(struct node *root){
    if(root ==NULL)
    return;
    postorderDis(root->left);
    postorderDis(root->right);
    printf("%d->",root->data);
}
void delete(){
    if(root==NULL)
    {
        printf("\nNo node to Delete");
        return;
    }
    int x;
    printf("\nEnter the node to delete: ");
    scanf("%d",&x);
    root=deleteEle(root,x);
    inorderDis(root);
    return;
}
struct node* deleteEle(struct node *root,int x){
    if(root==NULL){
        return root;
    }
    else if(x<root->data){
        root->left=deleteEle(root->left,x);
    }
    else if(x>root->data){
        root->right=deleteEle(root->right,x);
    }
    else{
        if(root->left==NULL && root->right==NULL){
            free(root);
            return NULL;
        }
        else if(root->left==NULL){
            struct node *temp;
            temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            struct node *temp;
            temp=root->left;
            free(root);
            return temp;
        }
        else{
            struct node *succ;
            succ=findSucc(root);
            root->data=succ->data;
            root->right=deleteEle(root->right,succ->data);
        }

    }
    return root;
}
struct node* findSucc(struct node *root){
    struct node *temp=root->right;
    while (temp->left!=NULL)
    {
        temp=temp->left;
    }
    return temp;
    
}

void main(){
    create();
    postorderDis(root);
}
