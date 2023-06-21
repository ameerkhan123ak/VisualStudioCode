#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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
void inorderTraversal(TreeNode* root)
{
    if(root==NULL) return;
    printf("%d ",root->data);
    inorderTraversal(root->left);
    inorderTraversal(root->right);
}
TreeNode* commonAncestors(TreeNode* root,int data1,int data2)
{
    if(root==NULL) return NULL;

    if(root->data == data1 || root->data == data2)
    return root;

    TreeNode* leftNode = commonAncestors(root->left,data1,data2);
    TreeNode* rightNode = commonAncestors(root->right,data1,data2);

    if(leftNode && rightNode) return root;
    else if(leftNode) return leftNode;
    else if(rightNode) return rightNode;
    else return NULL;
}
int main()
{
    buildTree();
    TreeNode* node =  commonAncestors(root,40,50); printf("%d",node->data);
    //inorderTraversal(root);
}