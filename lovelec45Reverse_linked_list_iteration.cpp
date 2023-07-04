#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    //construtor
    Node(int d)
    {
        this -> data = d;
        this -> next = NULL;
    }
    //destructor
    ~Node()
    {
        int value = this -> data;
        if(this - next != NULL)
        {
            delete next;
            this-> next = NULL;
        }
        cout<<"memory is free for node with data "<<value<<endl;
    }


    void reverselinkedlist(Node* head)
    {
        if(head == NULL || head -> next == NULL )
        {
            return head;
        }

        Node* prev = NULL;
        Node* curr = head;
        Node* forward = NULL;


        while(curr != NULL)
        {
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;

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
}

int main()
{
/*
    Node* node1 = new Node(10);
   // cout<< node1 ->data<<endl;
   // cout<<node1 ->next <<endl;
    //head pointed to  node1
    Node* head = node1;
    Node* tail = node1;
//  Node* position = node1;
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
    */
}

















