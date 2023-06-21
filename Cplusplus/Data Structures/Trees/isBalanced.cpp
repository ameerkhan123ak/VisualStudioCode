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
    int checkBalanced(TreeNode* root)
    {
        if(root==NULL) return 0;
        int lh = checkBalanced(root->left);
        if(lh==-1) return -1;
        int rh = checkBalanced(root->right);
        if(rh==-1) return -1;

        if(abs(lh-rh)>1) return -1;
        return max(lh,rh)+1;
    }
    bool isBalanced(TreeNode* root)
    {
        return checkBalanced(root) != -1;
    }
};
int main()
{
    buildTree();
    Solution s; 
    if(s.isBalanced(root)) cout<<"Balanced";
    else cout<<"NOT BALANCED";
}