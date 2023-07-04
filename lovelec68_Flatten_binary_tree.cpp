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
    void Flatten(Node* root)
    {
        Node* curr = root;
        while(curr!= NULL)
        {
           if(curr->left)
           {
            Node*pred = curr->left;
            while(pred->right)
            {
                pred = pred->right;
            }
            pred->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
           }
        curr = curr->right;
        }
        
    }
};
void levelOrderTraversal(Node* root)
{
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        if(temp == NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
int main()
{
    Node* root = NULL;
    root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->right = new Node(7);
    root->right = new Node(3);
    root->right->right = new Node(6);

    Solution obj;
    obj.Flatten(root);
    levelOrderTraversal(root);
    
   
}