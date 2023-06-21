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
vector<int> inorderTraversal(TreeNode* root)
{
    stack<TreeNode*> s;
    TreeNode* node = root;
    vector<int> inorder;
    while(true)
    {
        if(node != NULL)
        {
            s.push(node);
            node = node->left;
        }
        else  
        {
            if(s.empty()) break;
            
            node = s.top();
            s.pop();
            inorder.push_back(node->data);
            node = node->right;
        }
    }
    return inorder;
}
int main()
{
    buildTree();
    vector<int> ans = inorderTraversal(root);
    for(auto i: ans) cout<<i<<" ";
}