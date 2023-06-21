#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}TreeNode;

TreeNode* root = NULL;

TreeNode* createNode(int data)
{
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void buildTree()
{
    root = createNode(10);
    root->left = createNode(20);
    root->right = createNode(30);
    root->left->left = createNode(40);
    root->left->right = createNode(50);
    root->right->left = createNode(60);
    root->right->right = createNode(70);
}

void inorderTraversal(TreeNode* root)
{
    if(root==NULL) return;
    inorderTraversal(root->left);
    printf("%d ",root->data);
    inorderTraversal(root->right);
}

int Search(TreeNode* root,int k)
{
    if(root==NULL) return 0;
    if(root->data == k) return 1;
    int lp = Search(root->left,k);
    int rp = Search(root->right,k);
    return lp || rp;
}
int main()
{
    buildTree();
    int ans = Search(root,50); printf("%d",ans);
}