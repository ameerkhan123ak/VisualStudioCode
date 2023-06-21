#include<stdio.h>
#include<stdlib.h>


struct lnode{//define node
    int data;
    struct lnode* prev;
    struct lnode* next; //self referential str
};

static int size=0;
typedef struct lnode node;

node* head = NULL;
node* tail = NULL;

node* createNode()
{
    node* temp = (node*)malloc(sizeof(node));
    temp->prev = NULL;
    printf("Enter the data: ");
    scanf("%d",&temp->data);
    temp->next=NULL;
    size++;
    return temp;
}
void insertAtBeginning(){
    if(head == NULL)
    {
        node* newNode = createNode();
        head = tail = newNode;
    }
    else 
    {
        node* newNode = createNode();
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }    
}
void insertAtEnd()
{
    node* newNode = createNode();
    if(head == NULL)
    {
        insertAtBeginning();
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}
void insertAtPos()
{
    int pos;
    printf("Enter the Position: ");
    scanf("%d",&pos);
    if(pos==1)
    {
        insertAtBeginning();
        return;
    }
    if(pos==size+1)
    {
        insertAtEnd();
        return;
    }
    node* newNode = createNode();
    node* temp = head;
    for(int i=1;i<pos-1;i++)
    {
        temp = temp->next;
        if(temp==NULL)
        {
            printf("Invalid position !");
            return;
        }
    }
    newNode->next= temp->next;
    
    if(temp->next == NULL)
    {
        tail = newNode;
    }
    else 
    {
        temp->next->prev = newNode;
    }
    newNode->prev = temp;
    temp->next=newNode;
}
void display(){
    if(head==NULL){
        printf("List is empty");
        return;
    }
    node* temp = head;
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void displayReverse()
{
    if(tail == NULL)
    {
        printf("list is empty");
        return;
    }
    node* temp = tail;
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->prev;
    }
    printf("\n");
}
void deleteAtFirst()
{
    node* temp = head;
    if(head==NULL)
    {
        printf("list is empty");
        return;
    }
    head = head->next;
    head->prev = NULL;
    free(temp);
    temp=NULL;
    size--;
}
void deleteAtLast()
{
    node* temp = tail;
    if(tail==NULL)
    {
        printf("list is empty");
        return;
    }
    tail = tail->prev;
    tail->next = NULL;
    free(temp);
    size--;
}
void deleteAtPos()
{
    int pos;
    printf("Enter the Position: ");
    scanf("%d",&pos);
    if(pos==1)
    {
        deleteAtFirst();
        return;
    }
    if(pos==size)
    {
        deleteAtLast();
        return;
    }
    node* temp = head;
    node* previous = head;
    for(int i=1;i<pos;i++)
    {
        previous = temp;
        temp = temp->next;
        if(temp==NULL)
        {
            printf("Invalid position !");
            return;
        }
    }
    previous->next = temp->next;
    temp->next->prev = previous;
    free(temp);
    size--;

}
int main(){
    insertAtBeginning();
    insertAtBeginning();
    insertAtBeginning();
    insertAtEnd();
    insertAtEnd();
    insertAtEnd();
    deleteAtFirst();
    deleteAtPos();
    deleteAtLast();
    display();
    displayReverse();
    return 0;
}