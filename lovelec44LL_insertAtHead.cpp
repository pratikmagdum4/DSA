#include<iostream>
using namespace std;
class Node{

    public:
    int data;
    Node* next;
    //constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    
};
void insertAtTail(Node* &tail,int d)
{
    //new node create
    Node*temp = new Node(d);
    tail ->next = temp;
    tail = tail -> next;//or tail = temp also works instead
}
void insertAtHead(Node *&head, int d)
{   //create a new node
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}
void print(Node* &head)
{
    Node * temp = head;
    while(temp != NULL)
    {
        cout<<temp-> data<<" ";
        temp  = temp ->next;
    }
    cout<<endl;
}
int main()
{   //created a new node
    Node* node1 = new Node(10);
   // cout<< node1 ->data<<endl;
   // cout<<node1 ->next <<endl;
    //head pointed to  node1
    Node* head = node1;
    print(head);
    cout<<"hi"<<endl;
    insertAtHead(head,12);
    print(head);

    insertAtHead(head,15);
    print(head);

    return 0;
}