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
void insertAtPosition(int pos,int data)
{
    if(pos==1)
    {
        insertAtBeginning(data);
        return;
    }
    Node* newNode = createNode(data);
    Node* temp = head;
    for(int i=1;i<pos-1;i++) temp = temp->next;
    newNode->next = temp->next;
    temp->next = newNode;
}
void deleteAtBeginning()
{
    Node* temp = head;
    head = head->next;
    free(temp);
}
void deleteAtEnd()
{
    Node* temp = head;
    Node* prev = head;
    if(head==NULL) return;
    if(head->next==NULL) 
    {
        deleteAtBeginning();
        return;
    }
    while(temp->next!=NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
}
void deleteAtPosition(int pos)
{
    Node* temp = head;
    Node* prev = NULL;
    if(pos==1) 
    {
        deleteAtBeginning();
        return;
    }
    for(int i=1;i<pos;i++)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
}
void reverseLinkedList()
{
    Node* prevNode = NULL;
    Node* currNode = head;
    Node* nextNode = NULL;
    while(currNode != NULL)
    {
        nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }
    head = prevNode;
}
Node* reverseLinkedListRecursion(Node* node)
{
    if(node==NULL) return NULL;
    if(node->next == NULL) 
    {
        head = node;
        return node;
    }
    Node* temp = reverseLinkedListRecursion(node->next);
    temp->next = node;
    node->next = NULL;
    return node;
}
void display()
{
    Node* temp = head;
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void reverseDisplay(Node* temp)
{
    if(temp==NULL) return;
    reverseDisplay(temp->next);
    printf("%d ",temp->data);
}
int main()
{
    insertAtEnd(91);
    insertAtEnd(48);
    insertAtEnd(11);
    insertAtEnd(56);
    insertAtEnd(96);
    insertAtEnd(69);
    insertAtEnd(21);
    insertAtEnd(64);
    insertAtEnd(6);
    insertAtEnd(80);
    insertAtEnd(20);
    insertAtEnd(41);
    display();
}