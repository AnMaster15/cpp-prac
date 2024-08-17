#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}

int count(Node *head)
{
    Node *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    cout << cnt << endl;
}

void insertathead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *newnode = new Node(data);
        head = tail = newnode;
    }
    else
    {
        Node *newnode = new Node(data);
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}

void insertattail(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *newnode = new Node(data);
        head = tail = newnode;
    }
    else
    {
        Node *newnode = new Node(data);
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}

void insertatanaypaoint(Node *&head, Node *&tail, int data, int pos)
{
    if (pos == 0)
    {
        insertathead(head, tail, data);
    }
    else if (pos >= count(head))
    {
        insertattail(head, tail, data);
    }
    else
    {
        Node *newnode = new Node(data);
        Node *prevnode = NULL;
        Node *currnode = head;
        while (pos != 1)
        {
            prevnode = currnode;
            currnode = currnode->next;
            pos--;
        }
        prevnode->next = newnode;
        newnode->prev = prevnode;
        newnode->next = currnode;
        currnode->prev = newnode;
    }
}

void deleteNode(Node* &head,Node* &tail,int pos){
    int len=count(head);
    if(head==NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    if(pos==1){
        Node* temp=head;
        head=head->next;
        head->prev=NULL;
        temp->next=NULL;
        delete temp;
    }else if(pos>=len-1){
        Node* temp = tail;
        tail = tail->prev;
        temp->next=NULL;
        tail->prev=NULL;
         tail=temp;
        delete tail;
       
    }else{
        Node* prevnode=NULL;
        Node* currnode=head;

        while(pos!=1){
            prevnode=currnode;
            currnode=currnode->next;
            pos--;
        }
        Node* nextnode=currnode->next;
        prevnode->next=nextnode;
        nextnode->prev=prevnode;
        currnode->next=NULL;
        currnode->prev=NULL;
        delete currnode;
    }
}

int main()
{

    // Node* head = new Node(10);

    Node *head = NULL;
    Node *tail = NULL;
    insertathead(head, tail, 5);
    insertathead(head, tail, 15);
    insertathead(head, tail, 25);
    insertathead(head, tail, 35);
    insertatanaypaoint(head,tail,69,3);
    deleteNode(head,tail,5);
    print(head);

    return 0;
}