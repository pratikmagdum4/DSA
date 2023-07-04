

//PENDING DRIVER CODE

#include<iostream>
#include<vector>
using namespace std;
//Node for LL
struct Node{
    int data;
    struct Node* next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution {
    public:
    //reversing the LL
    Node* reverse(Node* head)
    {
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;

        while(curr!= NULL)
        {
            next  = curr->next;
            curr->next  = prev;
            prev = curr;
            curr = next;
        }
    }
    void insertAtTail(struct Node* &head, struct Node* &tail, int val)
    {
        Node* temp = new Node(val);
        if(head == NULL)
        {
            head = temp;
            tail = temp;
            return ;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
    }

    struct Node* add(struct Node* first ,struct Node* second)
    {
        int carry = 0;

        Node* ansHead = NULL;
        Node* ansTail = NULL;

        while(first!= NULL && second != NULL)
        {
            int sum = carry +first->data+second->data;
            int digit = sum%10;

            //create node and insert in  answer LL
            insertAtTail(ansHead,ansTail,digit);
            carry = digit/10;
            first= first->next;
            second = second->next;
        }

        while(first!= NULL)
        {
            int sum = carry + first->data;
            int digit = sum%10;
            insertAtTail(ansHead,ansTail,digit);
            carry = sum/10;
            first = first->next;

        }
        while(second!= NULL)
        {
            int sum = carry + first->data;
            int digit = sum%10;
            insertAtTail(ansHead,ansTail,digit);
            carry = sum/10;
            second = second->next;
            
        }

        while(carry != 0)
        {
            int sum = carry;
            int digit = sum %10;
            insertAtTail(ansHead,ansTail,digit);
            carry = sum/10;
        }

        return ansHead;
    }
    public:
    //function TO add 2 numbers represented be LL
    struct Node* addTwoLists(struct Node* first , struct Node* second)
    {
        //step 1: reverse input LL
        first = reverse(first);
        second = reverse(second);

        //step2:- add 2 LL
        Node* ans  = add(first, second);

        //step3 
        ans  = reverse(ans);
        return ans;
    }
};

int main()
{
    Solution s;
    Node* first = new Node(4);
    first->next = new Node(5);

    Node* second = new Node(3);
    second->next = new Node(4);
    second->next->next = new Node(5);

    cout<<  s.addTwoLists(first,second);
   
//   while(ans!= NULL)
//   {
//     cout<<ans->data<<endl;
//     ans = ans->next;
//   }
}