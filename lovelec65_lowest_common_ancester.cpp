#include<iostream>
#include<bits/stdc++.h>
#include<limits.h>
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
    //Function to return lowest common ancestor in a Binary tree
    Node* lca(Node* root, int n1,int n2)
    {
        //base case
        if(root == NULL)
        {
            return NULL;
        }
        if(root->data == n1 ||root->data == n2)
        {
            return root;
        }

        Node* leftAns = lca(root->left, n1,n2);
        Node* rightAns = lca(root->right, n1,n2);

        if(leftAns != NULL && rightAns != NULL)
        {
            return root;
        }
        else if(leftAns != NULL && rightAns == NULL)
        {
            return leftAns;
        }
        else if(leftAns == NULL && rightAns != NULL)
        {
            return rightAns;
        }
        else{
            return NULL;
        }
    }
};
int main()
{
    Solution obj;
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left  = new Node(6);
    root->left->left->right  = new Node(8);
    //root->left->right->left  = new Node(12);
    //root->left->right->right  = new Node(9);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);
    root->right->right->left = new Node(21);

    Node* ans =  obj.lca(root,21,4);
    cout<<ans->data<<endl;


}