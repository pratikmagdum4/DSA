#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};


class Solution{
    public:
    void solve(Node* root, int sum , int &maxSum,int len, int maxLen)
    {
        //base case
        if(root == NULL)
        {
            if(len>maxLen)
            {
                maxLen = len;
                maxSum = sum;
            }
            else if(len == maxLen)
            {
                maxSum = max(sum, maxSum);
            }
            return;
        }

        sum  = sum + root->data;
        solve(root->left, sum, maxSum, len+1,maxLen);
        solve(root->right, sum, maxSum, len+1,maxLen);
    }
    int sumOfLongRootToLeafPath(Node* root)
    {
        int len = 0;
        int maxLen  = 0;

        int sum = 0;
        int maxSum = 0;

        solve(root, sum , maxSum, len , maxLen);
        return maxSum;
    }
};
int main()
{
    Node* root = new Node(3);
    root->left = new Node(2);
    root->left->left = new Node(1);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(71);
    root->right = new Node(8);
   // root->right->right = new Node(9);
    //root->right->right->left = new Node(10);

    Solution obj;
  int ans =   obj.sumOfLongRootToLeafPath(root);
  cout<<"The ans is "<<ans<<endl;
}

