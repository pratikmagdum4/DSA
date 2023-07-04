#include<iostream>
class Node{
    public:
    int data;
    Node






}
//it will return head of reverse list 
Node* reverse1(Node*head)
{
    //base case 
    if(head == NULL || head -> next == NULL )
    {
        return head;
    }
    Node* chotahead = reverse1(head-> next);
    head -> next -> next = head;
    head -> next = NULL;
    return chotahead;
}