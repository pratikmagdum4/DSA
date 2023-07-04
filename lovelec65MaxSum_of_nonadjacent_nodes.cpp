#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
class Solution{
    public:
    //Function to return the maximum sum of non-adjacent nodes
    pair<int,int> solve(Node* root)
    {
        //base case
        if(root==NULL)
        {
            return {0,0};
        }
       pair<int,int>left = solve(root->left);
       pair<int,int>right = solve(root->right);

       pair<int,int>res;
       res.first = root->data + left.second+ right.second;
       res.second = max(left.first,left.second)+ max(right.first,right.second);

       return res;
    }
    int getMaxSum(Node* root)
    {
        pair<int,int> ans = solve(root);
        return max(ans.first,ans.second);
    }
};
int main()
{
    Solution s;
    Node* root = new Node(1);
    root->left  = new Node(2);
    root -> left->left = new Node(4);
    root->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
   int ans =  s.getMaxSum(root);
   cout<<ans<<endl;
}