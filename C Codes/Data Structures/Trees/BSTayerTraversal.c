#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}TreeNode;

TreeNode* root = NULL;

TreeNode* createTreeNode(int data)
{
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
TreeNode* insert(TreeNode* root,int data)
{
    if(root==NULL) return createTreeNode(data);
    if(data < root->data)
    root->left = insert(root->left,data);
    else if(data > root->data)
    root->right = insert(root->right,data);
    return root;
}
void enque(TreeNode* queue[],int *frontIndex,int *rearIndex,TreeNode* enque_val)
{
    if(*frontIndex==-1 || (*frontIndex > *rearIndex)) //Empty Queue
    {
        *frontIndex = *rearIndex = 0;
        queue[*frontIndex] = enque_val;
        return;
    }
    (*rearIndex)++;
    queue[*rearIndex] = enque_val;
}
TreeNode* deque(TreeNode* queue[],int *frontIndex,int *rearIndex)
{
    TreeNode* temp;
    if((*frontIndex == -1 || *rearIndex == -1) || (*frontIndex > *rearIndex)) return NULL;
    temp = queue[*frontIndex];
    (*frontIndex)++;
    return temp;
}
void levelOrderDisplay(TreeNode* root)
{
    TreeNode* queue[100];
    int rearIndex=-1,frontIndex=-1;
    enque(queue,&frontIndex,&rearIndex,root);
    while(1)
    {
        TreeNode* dequeVal = deque(queue,&frontIndex,&rearIndex);
        if(dequeVal==NULL) break;
        printf("%d ",dequeVal->data);
        enque(queue,&frontIndex,&rearIndex,dequeVal->left);
        enque(queue,&frontIndex,&rearIndex,dequeVal->right);
    }
}
int main()
{
    root = createTreeNode(50);
    insert(root,30);
    insert(root,20);
    insert(root,40);
    insert(root,70);
    insert(root,60);
    insert(root,90);
    levelOrderDisplay(root);
}