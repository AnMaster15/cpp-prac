#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->next = NULL;
        this->data = data;
    }

    Node()
    {
        this->next = NULL;
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
    while (temp != 0)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

void insertionathead(Node *&head, int data)
{

    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
    }
    else
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
}

void insertionattail(Node *&tail, int data)
{
    if(tail == NULL){
        Node* newNode =new Node(data);
        tail = newNode;
    }else{
        Node* newNode =new Node(data);
        tail->next=newNode;
        tail=newNode;
    }
}

void insertionattailwithhead(Node *&tail,Node* &head, int data)
{
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node* newNode =new Node(data);
    temp->next=newNode;
    tail=newNode;
}

void insertatanypoint(Node* &head,Node* &tail,int pos,int data){
    if(head==NULL){
        Node* newNode =new Node(data);
        head=newNode;
        tail=newNode;
    }
    
    int len=count(head);
   
    if(pos<=1){
        insertionathead(head,data);
    }
    else if(pos>len){
        insertionattailwithhead(tail,head,data);
    }else{
        Node* newNode=new Node(data);

        Node* prev=NULL;
        Node* curr=head;

        while(pos!=1){
            prev=curr;
            curr=curr->next;
            pos--;
        }

        prev->next=newNode;
        newNode->next=curr;



    }

}

void deleteNode(Node* &head,Node* &tail,int pos){
    if(head==NULL){
        cout<<"can't be delete"<<endl;
        return;
    }
    int len=count(head);

    if(pos==1){
        Node* temp=head;
        head=head->next;
        delete temp;
    }else if(pos==len){
        Node* prev=head;
        while(prev->next!=tail){
            prev=prev->next;
        }
        prev->next=NULL;
        delete tail;
        tail=prev;

    }else{
        Node* prev=NULL;
        Node* curr=head;

        while(pos!=1){
            prev=curr;
            curr=curr->next;
            pos--;
        }

        prev->next=curr->next;
        delete curr;
    }


}



int main()
{


    Node *head = NULL;
    Node *tail = NULL;

    insertionathead(head, 5);
    insertionathead(head, 4);
    insertionathead(head, 3);
    insertionattailwithhead(tail,head, 6);
    insertatanypoint(head,tail,5,500);

    deleteNode(head,tail,5);

    print(head);

    // Node a(6);//static bvalue
    // Node b;//static

    // Node *c = new Node(7); // dynamic
    // Node *d = new Node(8); // dynamic
    // Node *e = new Node(10);
    // Node *f = new Node(15);
    // Node *g = new Node(25);

    // c->next = d;
    // d->next = e;
    // e->next = f;
    // f->next = g;

    // Node *head = c;
    // Node *tail = g;

    // insertionathead(head, 5);
   
    // // count(head);
    // // link list create
    // insertionattail(tail, 50);
    // print(head);

    return 0;
}