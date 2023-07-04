#include<iostream>
using namespace std;
class Node{
    public:
    //constructor
    Node(int data)
    {
        this -> data = data;
        this -> next = next;
    }
    int data;
    Node* next;

    insertAtfirst(Node* &head,Node* &tail , int data){
        Node* list
        Node* curr = head;
        //for empty linked list
        if(curr-> next = NULL)
        {
            return NULL;
        }

        //for non-empty linked list


    }
    Node* uniqueSortedList(Node*head)
    {
    //empty list
    if(head == NULL)
    return NULL;

    //non-empty list
    Node*curr = head;
    while(curr != NULL)
    {
        if((curr -> next != NULL ) && curr -> data == curr -> next -> data)
        {
            Node* next_next = curr -> next -> next;
            delete(nodeToDelete);
            curr -> next = next_next;
        }
        else//not equal
        {
            curr = curr -> next;
        }

    }
    return head;

    }

}