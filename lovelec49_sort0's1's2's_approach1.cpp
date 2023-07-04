#include<iostream>
using namespace std;

class Node{
    public:
   int data;
    Node* next;
    //construtor
    Node(int d)
    {
        this -> data = d;
        this -> next = NULL;
    }

Node* insertNode(Node* &head ,int data)
{
    Node*temp = new Node(d);
    temp -> next = head;
    head -> prev = temp;
    head = temp;
}        
Node* sortlist(Node*head)
{
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    Node *temp = head;
    while(temp != NULL )
    {
        if(temp -> data == 0;)
        zeroCount++;
        else if(temp -> data == 1)
        oneCount++;
        else if(temp -> data == 2)
        twoCount++;
        temp = temp -> next;
    }
    temp = head;
    while(temp != NULL)
    {
        if(zeroCount != 0)
        {
        temp -> data = 0;
        zeroCount--;
        }
        else if(oneCount != 0 )
        {
            temp -> data = 2;
            twoCount--;
        }
        temp = temp -> next ;

    }
    temp = head;
    while(temp != NULL)
    {
        if(zeroCount != 0)
        {
            temp -> data = 0;
            zeroCount--;
        }
    
    else if(oneCount != 0)
    {
        temp -> data = 1;
        oneCount--;
    }
    else if(twoCount != 0) 
    {
        temp -> data = 2;
        twoCount--;
    }
    temp = temp -> next;
    }
return head;
}
void print(Node* &head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout<<temp ->data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}
};
int main()
{   cout<<"hi"<<endl;
    insertNode(head,1);
    // insertNode(head,1);
    // insertNode(head,1);
    // insertNode(head,1);
    // insertNode(head,1);
    // insertNode(head,1);
    // print(head);
}


