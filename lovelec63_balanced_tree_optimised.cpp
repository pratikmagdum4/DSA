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
    pair<bool, int> isBalancedFast(Node* root)
    {
        //base case
        if(root == NULL)
        {
            pair<bool,int>p = make_pair(true,0);
            return p;
        }

        pair<int,int> left = isBalancedFast(root->left);
        pair<int,int> right = isBalancedFast(root->right);

        bool leftAns = left.first;
        bool rightAns = right.first;

        bool diff = abs(left.second -right.second)<=1;
        pair<bool,int> ans;
        ans.second = max(left.second,right.second) +1;

        if(leftAns&&rightAns&& diff)
        {
            ans.first = true;
        }
        else{
            ans.first = false;
        }
        return ans;
    }

    bool isBalanced(Node* root)
    {//The first part of pair stores boolean value and second part stores Height of tree
        return isBalancedFast(root).first;
    }

};
Node* build(Node* root)
{
    cout<<"enter the data"<<endl;
    int data;
    cin>>data;
    root = new Node(data);
    if(data== -1)
    {
        return NULL;
    }
    cout<<"enter the data to the left of "<<data<<endl;
        root->left =   build(root->left);
    cout<<"Enter the data to the right of "<<data<<endl;
    root->right = build(root->right);
    return root;
}
void LevelOrderTraversal(Node* root)
{
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        Node* temp= q.front();
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
    Solution obj;
    Node* root = NULL;
    root = build(root);
    LevelOrderTraversal(root);

    bool ans = obj.isBalanced(root);
    if(ans)
    {
        cout<<"The tree is balanced "<<endl;
    }
    else{
        cout<<"The tree is not balanced "<<endl;
    }
}