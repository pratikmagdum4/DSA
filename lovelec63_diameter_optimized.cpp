#include<iostream>
#include<bits/stdc++.h>
#include<limits.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution{
    public:
    pair<int,int> diameterFast(Node* root)
    {
        //base case
        if(root==NULL)
        {
            pair<int,int> p = make_pair(0,0);
            return p;
        }
        pair<int,int> left = diameterFast(root->left);
        pair<int,int> right = diameterFast(root->right);

        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second +1;

        pair<int,int> ans;
        ans.first = max(op1,max(op2,op3));
        ans.second = max(left.second,right.second) + 1;

        return ans;
    }

    int diameter(Node* root)
    {
        return diameterFast(root).first;//first part represent diameter and second part represent height ,
                                        // we want height so we return root.first
    }
};

Node* build(Node* root)
{
    cout<<"enter data"<<endl;
    int data;
    cin>>data;

    root = new Node(data);

    if(data == -1)
    {
        return NULL;
    }

    cout<<"Enter data to the left of "<<data<<endl;
    root->left = build(root->left);
    cout<<"Enter data to the right of "<<data<<endl;
    root->right = build(root->right);

    return root;
}

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

root = build(root);
levelOrderTraversal(root);







}



































