#include<iostream>
#include<bits/stdc++.h>
#include<limits.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution{
    private:
    int Height(Node* root)
    {
        if(root == NULL)
        {
            return 0;
        }

        int left = Height(root->left);
        int right = Height(root->right);

        int ans = max(left,right)+1;
        return ans;
    }
    public:
    int diameter(Node* root)
    {
        //base case
        if(root== NULL)
        {
            return 0;
        }

        int op1 = diameter(root->left);
        int op2 = diameter(root->right);
        int op3 = Height(root->left)+1+Height(root->right);

        int ans = max(op1,max(op2,op3));
        return ans;
    }
};
Node* build(Node* root)
{
    cout<<"Enter the node"<<endl;
    int data;
    cin>>data;
    root = new Node(data);

    if(data == -1)
    {
        return NULL;
    }

    cout<<"Enter the data for left of "<<data<<endl;
    root->left = build(root->left);
    cout<<"Enter the data for right of "<<data<<endl;
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
            if(temp->left){
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
    Solution obj;
    cout<<"Diameter of the tree is "<<obj.diameter(root)<<endl;
    
    return 0;
}

