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
    int height(TreeNode* root,int &diameter)
    {
        if(root==NULL) return 0;
        int lh = height(root->left,diameter);
        int rh = height(root->right,diameter);
        diameter = max(diameter,lh+rh);
        return max(lh,rh)+1;
    }
    int diameter(TreeNode* root)
    {
        int diameter=0;
        height(root,diameter);
        return diameter;
    }
};
int main()
{
    buildTree();
    Solution s; 
    cout<<s.diameter(root);
}