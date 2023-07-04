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
        left = right= NULL;
    }
};

class Solution{
    public:
    vector<int>topview(Node* root)
    {
        vector<int>ans;
        if(root == NULL)
        {
            return ans;
        }

        map<int,int>topNode;
        queue<pair<Node*,int> > q;

        q.push(make_pair(root,0));

        while(!q.empty())
        {
            pair<Node*, int>temp = q.front();
            q.pop();
            Node* frontNode = temp.first;
            int hd= temp.second;

            //if one value is present for a hd, then do nothing
            if(topNode.find(hd) == topNode.end())
            {
                topNode[hd] = frontNode->data;
            }
            if(frontNode->left)
            {
                q.push(make_pair(frontNode->left,hd-1));
            }
            if(frontNode->right)
            {
                q.push(make_pair(frontNode->right,hd+1));
            }
        }

        for(auto i:topNode)
        {
            ans.push_back(i.second);
        }
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
    vector<int>ans = obj.topview(root);
    for(int i= 0; i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }


}

