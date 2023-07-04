#include<iostream>
#include<bits/stdc++.h>
#include<limits.h>
using namespace std;

struct Node{
    int data;
    struct Node*left;
    struct Node*right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution{
    public:
    //Function to find the height of binary tree
    int Height(struct Node* root)
    {
        //base case
        if(root == NULL)
        {
            return 0;
        }

        int left = Height(root->left);
        int right = Height(root->right);

        int ans = max(left,right)+1;
        return ans;
    } 
};