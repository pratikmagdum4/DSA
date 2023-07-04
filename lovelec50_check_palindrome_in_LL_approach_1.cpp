#include<iostream>
#include<vector>
using namespace std;
//defination for LL
struct Node{
    int data;
    struct Node*next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
class Solution{
    public:
    bool checkPalindrome(vector<int>arr){
        int n = arr.size();
        int s = 0;
        int e = n-1;
        while(s<=e)
        {
            if(arr[s]!= arr[e])
            {
                return 0;
            }
            s++;
            e--;
        }
        return 1;
    }
    public:
        //function to check whether list is palindrome
        //converting LL into array
        bool isPalindrome(Node* head)
        {
            vector<int>arr;
            Node* temp = head;
            while(temp!= NULL)
            {
                arr.push_back(temp->data);
                temp = temp ->next;
            }
            return checkPalindrome(arr);
        }
    
};
int main()
{
    Solution s;
    Node* head = new Node(2);
    head->next = new Node(1);
    head->next->next = new Node(1);
    head->next->next->next = new Node(0);
    //Output will be 1 for palindrome and 0 for else
    cout<<s.isPalindrome(head)<<endl;
}