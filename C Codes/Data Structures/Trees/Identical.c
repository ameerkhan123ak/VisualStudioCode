#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* left;
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
    return node;
}

void buildTree1()
{
    root1 = createTreeNode(10);
    root1->left = createTreeNode(20);
    root1->right = createTreeNode(30);
    root1->left->left = createTreeNode(40);
    root1->left->right = createTreeNode(50);
    root1->right->left = createTreeNode(60);
    root1->right->right = createTreeNode(70);
}
void buildTree2()
{
    root2 = createTreeNode(10);
    root2->left = createTreeNode(20);
    root2->right = createTreeNode(30);
    root2->left->left = createTreeNode(40);
    root2->left->right = createTreeNode(50);
    root2->right->left = createTreeNode(60);
    root2->right->right = createTreeNode(70);
}
int isIdentical(TreeNode* root1,TreeNode* root2)
{
    if(!root1 && !root2) return 1;
    int lp,rp;
    if(root1 && root2)
        return (root1->data==root2->data && isIdentical(root1->left,root2->left) && isIdentical(root1->right,root2->right));
    return 0;
}
int main()
{
    buildTree1();
    buildTree2();
    printf("%d ",isIdentical(root1,root2));
}