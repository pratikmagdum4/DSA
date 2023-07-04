#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//Number of paths having their sum 'K'

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
    void solve(Node* root, int k , int &count, vector<int> path)
    {
        //base case
        if(root == NULL)
        {
            return;
        }

        path.push_back(root->data);
        //left
        solve(root->left,k,count,path);
        //right
        solve(root->right,k,count,path);

        //check for k sum
        int size = path.size();
        int sum = 0;
        for(int i = size-1;i>=0; i--)
        {
            sum += path[i];
            if(sum == k)
            {
                count++;
            }
        }
        path.pop_back();
    }
    int sumK(Node* root,int k)
    {
        vector<int> path;
        int count = 0;
        solve(root,k, count,path);
        return count;
    }
};
int main()
{
    Node * root = new Node(1);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(1);
    root->left->right->left = new Node(1);
    root->right = new Node(-1);
    root->right->right = new Node(5);
    root->right->right->right = new Node(6);
    root->right->left = new Node(4);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(2);

    Solution obj;
    int ans = obj.sumK(root,5);
    cout<<ans<<endl;
}