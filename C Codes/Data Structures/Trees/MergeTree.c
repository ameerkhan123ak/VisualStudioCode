#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node* right;
}TreeNode;

TreeNode* root1 = NULL;
TreeNode* root2 = NULL;

TreeNode* createTreeNode(int data)
{
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
}

void buildTree1()
{
    root1 = createTreeNode(2);
    root1->left = createTreeNode(1);
    root1->right = createTreeNode(4);
    root1->left->left = createTreeNode(5);
    // root1->left->right = createTreeNode(5);
    // root1->right->left = createTreeNode(6);
    // root1->right->right = createTreeNode(7);
}
void buildTree2()
{
    root2 = createTreeNode(3);
    root2->left = createTreeNode(6);
    root2->right = createTreeNode(1);
    // root2->left->left = createTreeNode(4);
    root2->left->right = createTreeNode(2);
    // root2->right->left = createTreeNode(6);
    root2->right->right = createTreeNode(7);   
}
void inorderTraversal(TreeNode* root)
{
    if(root==NULL) return;
    inorderTraversal(root->left);
    printf("%d ",root->data);
    inorderTraversal(root->right);
}
TreeNode* mergeTree(TreeNode* root1, TreeNode* root2)
{
    if(root1==NULL) return root2;
    if(root2==NULL) return root1;
    root1->data = root1->data + root2->data;
    root1->left = mergeTree(root1->left,root2->left);
    root1->right = mergeTree(root1->right,root2->right);
    return root1;
}
int main()
{
    buildTree1();
    buildTree2();
    inorderTraversal(root1); printf("\n");
    mergeTree(root1,root2);
    inorderTraversal(root1);
}