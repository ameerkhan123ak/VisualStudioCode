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
    root = createNode(-10);
    root->left = createNode(9);
    root->right = createNode(20);
    root->right->left = createNode(15);
    root->right->right = createNode(7);
}
class Solution 
{
    public:
    int maximumPathDown(TreeNode* node,int &maxi)
    {
        if(node==NULL) return 0;
        int left = max(0,maximumPathDown(node->left,maxi));
        int right = max(0,maximumPathDown(node->right,maxi));

        maxi = max(maxi,left+right+node->data);
        
        return max(left,right) + node->data;
    }
    int maximumPathSum(TreeNode* root)
    {
        int maxi = INT_MIN;
        maximumPathDown(root,maxi);
        return maxi;
    }
};
int main()
{
    buildTree();
    Solution s;
    cout<<s.maximumPathSum(root);
}