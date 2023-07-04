#include<iostream>
#include<map>
using namespace std;

bool detectloop(Node* head)
{
    if(head == NULL)
    return false;


    map<Node*, bool>visited;
    Node* temp = head;
    while(temp != NULL)
    {
        //cycle is present
        if(visited[temp] == true)
        {
            cout<<"present on element "<<temp -> data <<endl;
            return true;  
        }
        visited[temp] = true;
        temp = temp -> next;
    }
    return false;
}