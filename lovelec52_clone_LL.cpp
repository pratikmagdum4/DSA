#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next; 
    Node* random;

    Node(int x)
    {
        data = x;
        next = NULL;
        random = NULL;
    }
};
//Node* copylist(Node* );
class Solution 
{
    public:
    void insertAtTail(Node* &head, Node* &tail, int d)
    {
        Node* newNode = new Node(d);
        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }
public:
    Node* copylist(Node* head)
    {
        //step1  = create a clone list

        Node* cloneHead = NULL;
        Node* cloneTail = NULL;

        Node* temp = head;
        while(temp!= NULL)
        {
            insertAtTail(cloneHead,cloneTail,temp->data);
            temp = temp->next;
        }

        //step 2 create a map
        unordered_map<Node*,Node*> oldToNewNode;
        Node* originalNode = head;
        Node* cloneNode = cloneHead;

        while(originalNode!= NULL && cloneNode != NULL)
        {
            oldToNewNode[originalNode]= cloneNode;
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }

        originalNode = head;
        cloneNode = cloneHead;
        // give random
        while(originalNode != NULL)
        {
            cloneNode ->random = oldToNewNode[originalNode->random];
            originalNode = originalNode->next ;
            cloneNode = cloneNode -> next;
        }
        return cloneHead;
    }
};

int main()
{
    Solution s;
    Node* head  = new Node(1);
    head ->next  = new Node(2);
    head ->next->next   = new Node(3);
    head ->next->next ->next  = new Node(4);
    head ->next->next ->next->next  = new Node(5);

    head -> random =  head ->next->next ;
    head->next ->random= head;
    head->next ->next->random =  head ->next->next ->next->next ;
    head ->next->next ->next->random = head ->next->next ;
    head ->next->next ->next->next ->random = head->next;

    Node* cloneNode =  s.copylist(head);
    Node* temp = cloneNode;
   
    // while(temp)
    // {
    //     cout<<temp->data<<" ";
    //     temp = temp->next;
    // }
    cout<<" The clone list is as follows"<<endl;
    while(temp) {
        cout << "Node data: " << temp->data;
        if(temp->random)
            cout << ", random node data: " << temp->random->data;
        cout << endl;
        temp = temp->next;
    }

}
// int main() {
//     // Create the original list
//     Node* head = new Node(1);
//     Node* node2 = new Node(2);
//     Node* node3 = new Node(3);

//     head->next = node2;
//     node2->next = node3;

//     head->random = node3;
//     node2->random = head;
//     node3->random = node2;

//     // Create a solution object
//     Solution s;

//     // Copy the list
//     Node* clonedHead = s.copylist(head);

//     // Print the original list and the cloned list
//     cout << "Original list: " << endl;
//     Node* temp = head;
//     while(temp) {
//         cout << "Node data: " << temp->data;
//         if(temp->random)
//             cout << ", random node data: " << temp->random->data;
//         cout << endl;
//         temp = temp->next;
//     }

//     cout << "Cloned list: " << endl;
//     Node* temp2 = clonedHead;
//     cout<<"hi"<<endl;
//     while(temp2!=NULL) {
//         cout << "Node data: " << temp2->data;
//         if(temp2->random)
//             cout << ", random node data: " << temp2->random->data;
//         cout << endl;
//         temp2 = temp2->next;
//     }
// cout<<"hi23"<<endl;
//     return 0;
// }