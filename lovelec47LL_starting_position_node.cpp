#include<iostream>
using namespace std;

Node*getstartingNode(Node* head)
{
    if(head ==NULL)
    return NULL;

    Node * intersection = floydDetectloo(head);
    Node* slow = head;

    while(slow != intersection)
    {
        slow = slow -> next;
        intersection = intersection->next;
    }
    return slow;
}