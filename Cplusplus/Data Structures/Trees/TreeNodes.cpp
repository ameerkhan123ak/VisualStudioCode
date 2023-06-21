#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
#include<queue>
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
void preorderTraversal(TreeNode* root)
{
    if(root==NULL) return;
    printf("%d ",root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void postorderTraversal(TreeNode* root)
{
    if(root==NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ",root->data);
}
int inorderTraversal2(TreeNode* root)
{
    stack<TreeNode*> s;
    vector<int> v;
    //if(root==NULL) return;
    while(1)
    {
        TreeNode* currNode = root;
        while(currNode != NULL)
        {
            s.push(currNode);
            currNode = currNode->left;
        }
        if(s.empty()) break;
        TreeNode* temp = s.top();
        s.pop();
        v.push_back(temp->data);
        //printf("%d ",temp->data);
        currNode = currNode->right;
    }
    return v.size();
}
int countNodes(TreeNode* root)
{
    if(root==NULL) return 0;
    int lp = countNodes(root->left);
    int rp = countNodes(root->right);
    return 1+lp+rp;
}
int countLeafNodes(TreeNode* root)
{
    if(root==NULL) return 0;
    if(root->left==NULL && root->right==NULL) return 1;
    int lp = countLeafNodes(root->left);
    int rp = countLeafNodes(root->right);
    return rp+lp;
}
int countNonLeafNodes(TreeNode* root)
{
    if(root==NULL) return 0;
    if(!root->left && !root->right) return 0;
    int lp = countNonLeafNodes(root->left);
    int rp = countNonLeafNodes(root->right);
    return lp+rp+1;
}
vector<vector<int>> BinaryTreeLevelOrderTraversal(TreeNode* root)
{
    vector<vector<int>> v;
    queue<TreeNode*> q;
    if(root==NULL) return v;
    while(!q.empty())
    {
        int count=q.size();
        vector<int> v1;
        while(count > 0)
        {
            TreeNode* currNode = q.front();
            q.pop();
            v1.push_back(currNode->data);
            printf("%d ",currNode->data);
            if(currNode->left) q.push(currNode);
            if(currNode->right) q.push(currNode->right);
            count--;
        }
        v.push_back(v1);
    }
    return v;
}
void printKthLevel(TreeNode* root,int k)
{
    if(root==NULL) return;
    if(k==1)
    {
        cout<<root->data<<" ";
        return;
    }
    printKthLevel(root->left,k-1);
    printKthLevel(root->right,k-1);
}
void leafSum2(TreeNode* root,int rs)
{
    if(root==NULL) return;
    if(!root->left && !root->right) cout<<rs*10 + root->data<<" ";
    leafSum2(root->left,(rs*10 + root->data));
    leafSum2(root->right,(rs*10 + root->data));
}
int sumNumbers(TreeNode* root)
{
    vector<int> v;
    int res=0;
    for(auto i: v)
    {
        res += i;
    }
    return res;
}
bool ispresent(TreeNode* root,int target)
{
    if(root==NULL) return false;
    if(root->data == target) return true;
    int lp = ispresent(root->left,target);
    int rp = ispresent(root->right,target);
    return lp || rp; 
}
void computeMinMax(TreeNode* root,int hd,int *pmin,int *pmax)
{
    if(root==NULL) return;
    if(hd<*pmin) *pmin=hd;
    if(hd>*pmax) *pmax = hd;
    computeMinMax(root->left,hd-1,pmin,pmax);
    computeMinMax(root->right,hd+1,pmin,pmax);
}
void printVerticalOrderTraversal(TreeNode* root,int k,int hd)
{
    vector<int> v;
    if(root==NULL) return;
    if(k==hd) cout<<root->data<<" ";
    printVerticalOrderTraversal(root->left,k,hd-1);
    printVerticalOrderTraversal(root->right,k,hd+1);
}
void verticalOrderTraversal(TreeNode* root)
{
    int min=0,max=0;
    computeMinMax(root,0,&min,&max);
    for(int k=min;k<=max;k++)
    printVerticalOrderTraversal(root,k,0);
}
int Maximum(TreeNode* root)
{
    if(root==NULL) return INT_MIN;
    int max = root->data;
    int lmax = Maximum(root->left);
    int rmax = Maximum(root->right);
    if(lmax > rmax) max = lmax;
    else if(rmax > lmax) max = rmax;
    return max;
}
int main()
{
    BuildTree();
    postorderTraversal(root);
}
