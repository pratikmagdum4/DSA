
//OPTIMIZED CODE
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
        return prev;
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

        while(first!= NULL || second != NULL||carry != 0)
        {
            int val1=  0;
            if(first != NULL)
                val1 = first->data;

            int val2=  0;
            if(second != NULL)
                val2 = second->data;

            int sum = carry +val1+val2;
            int digit = sum%10;

            //create node and in answer LL
            insertAtTail(ansHead,ansTail,digit);
            carry = sum/10;
            if(first!= NULL)
                first= first->next;

            if(second!=NULL)
                second = second->next;
            
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
    second->next = new Node(3);
    second->next->next = new Node(5);

    Node* ans = s.addTwoLists(first,second);
   // cout<<"hi"<<endl;
    while(ans)
    {   
 
    cout<<ans->data;
    ans = ans->next;
    }
  // cout<<"hi"<<endl;
}