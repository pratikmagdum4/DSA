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
    void solve(Node* root, vector<int>&ans, int level)
    {
        //base case
        if(root == NULL)
        {
            return;
        }

        //we entered into a new level
        if(level == ans.size())
        {
            ans.push_back(root->data);
            solve(root->right,ans,level+1);
            solve(root->left,ans,level+1);
        }
    }
    vector<int>rightView(Node* root)
    {
        vector<int>ans;
        solve(root,ans,0);
        return ans;
    }
};
int main()
{
     Node* root = NULL;

    root = new Node(4);
    root->right = new Node(5);
    root->right->right = new Node(6);
    root->right->left = new Node(7);
    root->left = new Node(8);
    root->left->right=  new Node(9);
    root->left->left = new Node(10);
    Solution obj;

    vector<int>ans = obj.rightView(root);
    for(int i= 0 ; i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}