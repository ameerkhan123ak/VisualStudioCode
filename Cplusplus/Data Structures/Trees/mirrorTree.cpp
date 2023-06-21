#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

typedef struct node 
{
    struct node* left;
    int data;
    struct node* right;
}TreeNode;

TreeNode* root = NULL;

TreeNode* createTreeNode()
{
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
    cout<<"Enter the Data: ";
    cin>>temp->data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
void BuildTree()
{
    root = createTreeNode();
    root->left = createTreeNode();
    root->right = createTreeNode();
    TreeNode* t1 = root->left;
    TreeNode* t2 = root->right;
    t1->left = createTreeNode();
    t1->right = createTreeNode();
    t2->left = createTreeNode();
    t2->right = createTreeNode();
}
void inorderTraversal(TreeNode* root)
{
    if(root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ",root->data);
    inorderTraversal(root->right);
}
void mirror(TreeNode* root)
{
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode* curr = q.front();
        q.pop();
        swap(curr->left,curr->right);
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
}
int main()
{
    BuildTree();
    inorderTraversal(root); cout<<endl;
    mirror(root);
    inorderTraversal(root);
}
