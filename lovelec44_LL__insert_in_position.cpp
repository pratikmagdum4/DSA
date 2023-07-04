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
//void insertAtHead(Node *&head, int d);

void insertAtHead(Node *&head, int d)
{   //create a new node
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}
void insertAtTail(Node* &tail,int d)
{
    //new node create
    Node*temp = new Node(d);
    tail ->next = temp;
    tail = tail -> next;//or tail = temp also works instead
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

void insertAtPosition(Node* &tail ,Node* &head,int position, int d)
{   
    //Sequence is very very important, 
    Node*temp = head;//first write this
    int cnt= 1;//part
    //Insert at start
    if(position == 1)
    {
    insertAtHead(head,d);//then write this if statement
        return;
    }
    
   
    while(cnt <position-1)
    {
        temp = temp->next;//then write this while loop
        cnt++;
    }
    //Insert at last position
    if(temp -> next == NULL)
    {
    insertAtTail(tail, d);//this write this if statement
        return;
    }
    //creating a node for d
    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp ->next;//then this at last
    temp -> next = nodeToInsert;
}
int main()
{   //created a new node
    Node* node1 = new Node(10);
   // cout<< node1 ->data<<endl;
   // cout<<node1 ->next <<endl;
    //head pointed to  node1
    Node* head = node1;
    Node* tail = node1;
   // Node* position = node1;
    print(head);
    
    insertAtTail(tail,12);
    print(head);

    insertAtTail(tail,15);
    print(head);

    insertAtPosition(tail,head,4,34);
    print(head);

    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;

    return 0;
}