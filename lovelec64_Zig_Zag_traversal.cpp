#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node*left;
    Node*right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution{
    public:
    //Function to store the zig Zag order Traversal of tree in a list
    vector<int> zigZagTraversal(Node* root)
    {
        vector<int>result;
        if(root ==NULL)
        {
            return result;
        }
        queue<Node*>q;
        q.push(root);
        bool leftToRight = true;
        while(!q.empty())
        {
            int size = q.size();
            vector<int>ans(size);

            //Level process
            for(int i= 0 ; i<size ; i++)
            {
                Node* frontNode = q.front();
                q.pop();
                //Normal insert or reverse insert
                int index = leftToRight ? i: size-i-1;
                ans[index] = frontNode->data;
                if(frontNode->left)
                {
                    q.push(frontNode->left);
                }
                if(frontNode->right)
                {
                    q.push(frontNode->right);
                }
            }
            //direction change karni h
                leftToRight = !leftToRight;
                for(auto i :ans)
                {
                    result.push_back(i);
                }
            
        }
        return result;
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
    root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right = new Node(4);
    root->right->right = new Node(6);
    root->right->right->left = new Node(7);
    root->right->right->right = new Node(8);

    Solution obj;
    LevelOrderTraversal(root);
    cout<<endl;
    vector<int>ans = obj.zigZagTraversal(root);
    cout<<endl;
   // LevelOrderTraversal(root);
    for(int i = 0; i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}