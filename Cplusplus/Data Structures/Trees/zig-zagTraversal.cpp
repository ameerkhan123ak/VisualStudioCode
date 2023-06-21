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
    vector<vector<int>> zigzalevelOrder(TreeNode* root)
    {
        vector<vector<int>> result;
        if(root==NULL) return result;
        
        queue<TreeNode*> nodesQueue;
        nodesQueue.push(root);
        bool flag= true;
        while(!nodesQueue.empty())
        {
            int size = nodesQueue.size();
            vector<int> row(size);
            for(int i=0;i<size;i++)
            {
                TreeNode* node = nodesQueue.front();
                nodesQueue.pop();

                int index = (flag)?i:(size-1-i); //find position to fil nodes value
                row[index] = node->data;
                if(node->left)
                {
                    nodesQueue.push(node->left);
                }
                if(node->right)
                {
                    nodesQueue.push(node->right);
                }
            }
            flag = !flag;
            result.push_back(row);
        }
        return result;
    }
};
int main()
{
    buildTree();
    Solution s;
    vector<vector<int>> ans = s.zigzalevelOrder(root);
    for(auto i: ans)
    {
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

/*
TIME COMPLEXITY : O(n)
SPACE COMPLXITY: O(n)
*/