#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>

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
int height(TreeNode* root)
{
    if(root==NULL) return 0;
    int lp = height(root->left);
    int rp = height(root->right);
    return (lp>rp?lp:rp)+1;
}
bool checkBalanced(TreeNode* root)
{
    if(root==NULL) return true;
    
    bool left = checkBalanced(root->left);
    bool right = checkBalanced(root->right);

    int diff = abs(height(root->left) - height(root->right)) <= 1;

    if(left && right && diff) return true;
    else return false;
}
int main()
{
    buildTree();
    bool ans = checkBalanced(root); printf("%d",ans);
}