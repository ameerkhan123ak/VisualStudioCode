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
vector<int> postorderTraversal(TreeNode* root)
{
    vector<int> postorder;
    if(root==NULL) return postorder;
    stack<TreeNode*> s1,s2;
    s1.push(root);
    while(!s1.empty())
    {
        root = s1.top();
        s1.pop();
        s2.push(root);
        if(root->left != NULL) s1.push(root->left);
        if(root->right != NULL) s1.push(root->right);
    }
    while(!s2.empty())
    {
        postorder.push_back(s2.top()->data);
        s2.pop();
    }
    return postorder;
}
int main()
{
    buildTree();
    vector<int> ans = postorderTraversal(root);
    for(auto i: ans) cout<<i<<" ";
}