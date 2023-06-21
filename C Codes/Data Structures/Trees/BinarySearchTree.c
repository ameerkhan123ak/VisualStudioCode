#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct treenode
{
    int data;
    struct treenode* left;
    struct treenode* right;
}TreeNode;

TreeNode* root = NULL;

TreeNode* createTreeNode(int data)
{
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
}
TreeNode* insert(TreeNode* root,int data)
{
    if(root==NULL) return createTreeNode(data);
    if(data < root->data) root->left = insert(root->left,data);
    else if(data > root->data) root->right = insert(root->right,data);
    return root;
}
int search(TreeNode* root,int data)
{
    if(root==NULL) return 0;
    if(root->data == data) return 1; 
    if(data < root->data) search(root->left,data);
    else if(data > root->data) search(root->right,data);
}
TreeNode* minNode(TreeNode* node)
{
    if(node==NULL) return node;
    TreeNode* temp = node;
    while(temp && temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}
TreeNode* delete(TreeNode* root,int data)
{
    if(root==NULL) return root;
    if(data < root->data) root->left = delete(root->left,data);
    else if(data > root->data) root->right = delete(root->right,data);
    else
    {
        if(root->left == NULL)
        {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        TreeNode* temp = minNode(root->right);
        root->data = temp->data;
        root->right = delete(root->right,temp->data);
    }
    return root;
}
void inorderTraversal(TreeNode* root)
{
    if(root==NULL) return;
    inorderTraversal(root->left);
    printf("%d ",root->data);
    inorderTraversal(root->right);
}
int max(int a,int b) { return a>=b?a:b;}
int height(TreeNode* root)
{
    if(root==NULL) return 0;
    return 1 + max(height(root->left),height(root->right));
}
int isBalanced(TreeNode* root)
{
    if(root==NULL) return 1;
    int lh,rh;
    lh = height(root->left);
    rh = height(root->right);
    if(abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right)) return 1;
    return 0;

}
int main()
{
    root = createTreeNode(50);
    insert(root,20);
    insert(root,70);
    insert(root,10);
    insert(root,25);
    insert(root,60);
    insert(root,70);
    insert(root,90);
    inorderTraversal(root); printf("\n");
    inorderTraversal(root);
}