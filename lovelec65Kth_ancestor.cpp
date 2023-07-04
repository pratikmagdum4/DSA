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
        Node* solve(Node* root , int &k , int node)
        {
            //base case
            if(root == NULL)
            {
                return NULL;
            }
            if(root->data == node)
            {
                return root;
            }

            Node* leftAns = solve(root->left,k,node);
            Node* rightAns = solve(root->right,k,node);

            if(leftAns!= NULL&& rightAns == NULL)
            {
                k--;
                    if(k <= 0)
                    {
                        //answer lock
                        k = INT_MAX;
                        return root;
                    }
                    return leftAns; 
            }
            
            if(leftAns== NULL&& rightAns != NULL)
            {
                k--;
                    if(k <= 0)
                    {
                        //answer lock
                        k = INT_MAX;
                        return root;
                    }
                    return rightAns; 
            }
            return NULL;
        }
    int kthAncestor(Node* root,int k ,int node)
    {
        Node* ans = solve(root,k,node);
        if(ans == NULL ||ans->data == node)
        {
            return -1;
        }
        else{
            return ans->data;
        }
    }
};
int main()
{
    Node * root = new Node(1);
    root->left= new Node(3);

    
}