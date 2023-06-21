#include<bits/stdc++.h>
using namespace std;

typedef struct lnode
{
    int data;
    struct lnode* next;
}Node;

Node* head = NULL;

Node* createNode()
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->next = NULL;
    return newNode;
}
void insertAtBeginning(int val)
{
    if(head == NULL)
    {
        Node *newNode = createNode();
        newNode->data = val;
        head = newNode;
        return;
    }
    Node *newNode = createNode();
    newNode->data = val;
    newNode->next = head;
    head =  newNode;
}
void display()
{
    Node *temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
bool isDuplicate(Node* head)
{
    Node* temp = head;
    unordered_map<int,int> m;
    while(temp != NULL)
    {
        int val = temp->data;
        m[val]++;
        temp = temp->next;
    }
    for(auto i: m)
    {
        if(i.second > 1) return false;
    }
    return true;
}
void insertAtEnd(int val)
{
    Node* temp = head;
    if(head==NULL)
    {
        insertAtBeginning(val);
        return;
    }
    Node* newNode = createNode();
    newNode->data = val;
    while(temp->next != NULL)
    temp = temp->next;

    temp->next = newNode;
}
void insertAtPos(int index,int val)
{
    Node* newNode = createNode();
    newNode->data=val;
    Node* temp = head;
    for(int i=1;i<=index-1;i++)
    {
        temp = temp->next;
        if(temp==NULL) 
        {
            insertAtEnd(val);
            return;
        }
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
Node* removeElements(Node* head,int val)
{
    if(head==NULL) return head;
    if(head->data == val)
    {
        Node* temp = head->next;
        delete(head);
        return removeElements(temp,val);
    }
    head->next = removeElements(head->next,val);
    return head;
}
void deleteAtBeginning()
{
    Node* temp = head;
    if(head==NULL) return;
    head = head->next;
    delete(temp);
}
void deleteAtPos(int pos)
{
    Node* temp = head;
    Node* prev = NULL;
    if(pos==0)
    {
        deleteAtBeginning();
        return;
    }
    for(int i=1;i<=pos;i++)
    {
        prev = temp;
        temp = temp->next;
        if(temp==NULL) return;
    }
    prev->next = temp->next;
    delete(temp);
}
int findSecondMaximum(Node* head)
{
    set<int> s;
    Node* temp = head;
    while(temp != NULL)
    {
        int x = temp->data;
        s.insert(x);
        temp = temp->next;
    }
    int l = s.size();
    int ans;
    for(auto i: s)
    {
        if(--l == 0) break;
        ans = i;
    }
    return ans;
}
Node* reverseLinkedList(Node* head)
{
    stack<int> s;
    Node* temp = head;
    while(temp != NULL)
    {
        s.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(s.size())
    {
        temp->data = s.top();
        temp = temp->next;
        s.pop();
    }
    return head;
}
void sortLinkedList(Node* head)
{
    multiset<int> s;
    Node* temp = head;
    while(temp != NULL)
    {
        s.insert(temp->data);
        temp = temp->next;
    }
    temp = head;
    for(auto i: s)
    {
        temp->data = i;
        temp = temp->next;
    }
}
void deleteDuplicatesFromSortedList()
{
    Node* temp = head;
    if(head==NULL) return;
    set<int> s;
    while(temp != NULL)
    {
        s.insert(temp->data);
        temp = temp->next;
    }
    int count=0;
    temp = head;
    for(auto i: s)
    {
        temp->data = i;
        if(s.size() == ++count) break;
        temp = temp->next;   
    }
    temp->next = NULL;
}
void reverseLinkedListII(Node* head,int l,int r) // not finished
{
    Node* temp = head;
    Node* left = NULL;
    Node* right = NULL;
    int right_data;
    stack<int> s;
    if(temp->next == NULL) return;
    while(temp!=NULL)
    {
        if(temp->data == l)
        left = temp;
        else if(temp->data == r)
        {
            right = temp;
            s.push(temp->data); //cout<<"right: "<<temp->data<<endl;
            break;
        }
        if(left!=NULL && right==NULL)
        {
            s.push(temp->data);
            //cout<<temp->data<<endl;
        }
        temp = temp->next;
    }
    temp = head;
    while(left != right)
    {
        left->data = s.top();
        left = left->next;
        s.pop();
    }
    left->data = s.top();
    s.pop();
}
void removeDuplicates()
{
    Node* temp = head;
    map<int,int> m;
    while(temp != NULL)
    {
        m[temp->data]++;
        temp = temp->next;
    }
    temp = head;
    //for(auto i: m) cout<<i.first<<" "<<i.second<<endl;
    int count=0;
    for(auto i: m)
    {
        if(i.second==1) count++;
    }
    if(count==m.size()) return;
    for(auto i: m)
    {
        if(i.second==1)
        {
            temp = temp->next;
            temp->data = i.first;
        }
    }
    head = head->next;
    temp->next = NULL;
}
int main()
{
    insertAtEnd(1);
    /*insertAtEnd(1);
    insertAtEnd(1);*/
    insertAtEnd(1);
    //insertAtEnd(3);
    /*insertAtEnd(4);
    insertAtEnd(5);*/
    display(); cout<<endl;
    removeDuplicates();
    display();
}