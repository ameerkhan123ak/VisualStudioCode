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
class Solution 
{
    public:
    bool isLeaf(TreeNode* root)
    {
        return !root->left && !root->right;
    }
    void addLeftBoundary(TreeNode* root,vector<int> &res)
    {
        TreeNode* node = root->left;
        while(node)
        {
            if(!isLeaf(node)) res.push_back(node->data);
            if(node->left) node = node->left;
            else node = node->right;
        }
    }
    void addRightBoundary(TreeNode* root,vector<int> &res)
    {
        TreeNode* node = root->right;
        stack<int> s;
        while(node)
        {
            if(!isLeaf(node)) s.push(node->data);
            if(node->right) node = node->right;
            else node = node->left;
        }
        while(!s.empty())
        {
            res.push_back(s.top());
            s.pop();
        }
    }
    void addLeaves(TreeNode* root,vector<int> &res)
    {
        if(isLeaf(root))
        {
            res.push_back(root->data);
            return;
        }
        if(root->left) addLeaves(root->left,res);
        if(root->right) addLeaves(root->right,res);
    }
    vector<int> traverseBoundary(TreeNode* root)
    {
        vector<int> res;
        if(!root) return res;
        if(!isLeaf(root)) res.push_back(root->data);
        addLeftBoundary(root,res);
        addLeaves(root,res);
        addRightBoundary(root,res);
        return res;
    }
};
int main()
{
    buildTree();
    Solution s; 
    vector<int> ans = s.traverseBoundary(root);
    for(auto i:ans) cout<<i<<" ";
}