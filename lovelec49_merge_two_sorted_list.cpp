#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    t data;
    Node* next;
    Node(T data)
    {
        next = NULL;
        this ->data = data;
    }

    ~Node()
    {
        if(next!=NULL)
        {
            delete next;
        }
    }
};
Node<int>*solve(Node<int>*first,node<int>*second)
{
    //if only one element is present in 1st list point its next to entire second list
    if(first -> next == NULL)
    {
        first ->next = second;
        return first; 
    }
    Node<int>* curr1 = first;
    Node<int>*next1= curr1->next;
    Node<int>*curr2 =second;
    Node<int>*next2 =curr2->next;

    while(next1 != NULL && curr2 !=NULL)
    {
        if((curr2->data>=curr1->data)&&(curr2->data<=next1->data))
        {
            //add node in between the 1st list
            curr1->next = curr2;
            next2= curr->next;
        }
    }
}

int main()
{

}