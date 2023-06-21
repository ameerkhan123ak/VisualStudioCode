#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}TreeNode;
TreeNode *root = NULL;

TreeNode* createNode(int data)
{
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
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
    cout<<root->data<<" ";
    inorderTraversal(root->right);

}
int main()
{
    buildTree();
    inorderTraversal(root);
}