#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution{
    public:
    void traverseLeft(Node* root , vector<int> &ans)
    {
        //base case 
        if((root == NULL) ||(root->left == NULL&& root->right == NULL))
        {
            return;
        }
        ans.push_back(root->data);
        if(root->left)
            traverseLeft(root->left,ans);
        else
            traverseLeft(root->right,ans);
    }
    
    void traverseLeaf(Node* root, vector<int>&ans)
    {
        //base case
        if(root== NULL)
        {
            return;
        }
        if((root->left == NULL&& root->right == NULL))
        {
            ans.push_back(root->data);
        }
        traverseLeaf(root->left,ans);
        traverseLeaf(root->right,ans);
    }

    void traverseRight(Node* root, vector<int>&ans)
    {
        //base case 
        if((root == NULL) ||(root->left == NULL&& root->right == NULL))
        {
            return;
        }
        if(root->right)
            traverseRight(root->right,ans);
        else
            traverseRight(root->left,ans);

        //wapas ayega
        ans.push_back(root->data);
    }

    vector<int>boundary(Node* root)
    {
        vector<int>ans;
        if(root == NULL)
        {
            return ans;
        }
        ans.push_back(root->data);

        //left part store karo
        traverseLeft(root->left,ans);

        //traverse leaf nodes
        //left subtree
        traverseLeaf(root->left,ans);
        //right subtree
        traverseLeaf(root->right, ans);

        //traverse right part
        traverseRight(root->right, ans);

        return ans;
    }
};
void LevelOrderTraversal(Node* root)
{
    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node*temp = q.front();
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
    Solution obj;

    root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right = new Node(4);
    root->right->right = new Node(6);
    root->right->right->left = new Node(7);
    root->right->right->right = new Node(8);

    LevelOrderTraversal(root);
    cout<<endl;
    vector<int>ans = obj.boundary(root);
    for(int i= 0 ; i<ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
}