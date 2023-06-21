#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}Node;

Node *head = NULL;

Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertAtBeginning(int data)
{
    Node* newNode = createNode(data);
    if(head==NULL)
    {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}
void insertAtEnd(int data)
{
    if(head==NULL)
    {
        insertAtBeginning(data);
        return;
    }
    Node* newNode = createNode(data);
    Node* temp = head;
    while(temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    newNode->next = NULL;
}
Node* MiddleNode(Node* head)
{
    Node *fast,*slow;
    fast=slow=head;
    while(fast!=NULL)
    {
        fast = fast->next;
        if(fast!=NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
}
int main()
{
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtEnd(40);
    insertAtEnd(50);
    Node* ans = MiddleNode(head); printf("%d",ans->data);
}