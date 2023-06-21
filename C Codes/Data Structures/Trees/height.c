#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}TreeNode;

TreeNode* root = NULL;

TreeNode* createTreeNode(int data)
{
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
}

void buildTree()
{
    root = createTreeNode(10);
    root->left = createTreeNode(20);
    root->right = createTreeNode(30);
    root->left->left = createTreeNode(40);
    root->left->right = createTreeNode(50);
    root->right->left = createTreeNode(60);
    root->right->right = createTreeNode(70);
}
int findHeight(TreeNode* root)
{
    if(root==NULL) return 0;
    int lp = findHeight(root->left);
    int rp = findHeight(root->right);
    return (lp>rp?lp:rp)+1;
}
int main()
{
    buildTree();
    int height = findHeight(root);
    printf("%d",height);
}