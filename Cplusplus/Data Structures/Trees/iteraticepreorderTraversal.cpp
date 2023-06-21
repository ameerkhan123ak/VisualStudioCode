#include<bits/stdc++.h>
using namespace std;
typedef struct treenode
{
    int data;
    struct treenode* left;
    struct treenode* right;
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
vector<int> preorderTraversal(TreeNode* root)
{
    stack<TreeNode*> s;
    vector<int> preorder;
    s.push(root);
    while(!s.empty())
    {
        root = s.top();
        s.pop();
        preorder.push_back(root->data);
        if(root->right) s.push(root->right);
        if(root->left) s.push(root->left);
    }
    return preorder;
}
int main()
{
    buildTree();
    vector<int> ans = preorderTraversal(root);
    for(auto i: ans) cout<<i<<" ";
}