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
    //create mapping
    //return target node
    Node* createParentMapping(Node* root,int target,map<Node*,Node*> &nodeToParent)
    {
        Node* res = NULL;

        queue<Node*>q;
        q.push(root);
        nodeToParent[root] = NULL;
       
        while(!q.empty())
        {
            Node* front = q.front();
            q.pop();

            if(front->data == target)
            {
                res = front;
            }
            if(front->left)
            {
                nodeToParent[front->left] = front;
                q.push(front->left);
            }
            if(front->right)
            {
                nodeToParent[front->right] = front;
                q.push(front->right);
            }
        }
        return res;
    }
    int burnTree(Node* root, map<Node*,Node*> &nodeToParent)
    {
        map<Node*,bool>visited;
        queue<Node*> q;

        q.push(root);
        visited[root] = true;
        int ans = 0;
        while(!q.empty())
        {
            bool flag = 0;
            
            int size = q.size();
            for(int i = 0; i<size; i++)
            {
                //process neighboring nodes 
                Node* front = q.front();
                q.pop();

                if(front->left && !visited[front->left])
                {
                    flag = 1;
                    q.push(front->left);
                    visited[front->left]= 1;
                }
                if(front->right && !visited[front->right])
                {
                    flag = 1;
                    q.push(front->right);
                    visited[front->right]= 1;
                }
                //visit parent of front
                if(nodeToParent[front]&& !visited[nodeToParent[front]])
                {
                        flag = 1;
                        q.push(nodeToParent[front]);
                        visited[nodeToParent[front]] = 1;
                }
            }
            if(flag == 1)
            {
                ans++;
            }
        }
        return ans;
    }

    int minTime(Node* root,int target)
    {
        //algo:
        //step 1: create nodeToParent mapping
        //step 2: find target node
        //step 3: burn the tree in the min time
       
        map<Node*,Node*>nodeToParent;
        Node* targetNode = createParentMapping(root,target,nodeToParent);
        int ans  = burnTree(targetNode,nodeToParent);

        return ans;
    }
};
int main()
{
    Node* root = NULL;
    root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right = new Node(5);
    root->right->right = new Node(6);
    root->right->left = new Node(7);
    root->right->right->left = new Node(8);
    int target = 1;
    Solution obj;
    int ans = obj.minTime(root,target);
    cout<<ans<<endl;
}