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
    void createMapping(int in[],map<int,int> &nodeToIndex,int n)
    {
        for(int i = 0; i<n; i++)
        {
            nodeToIndex[in[i]] = i;
        }
       
    }
    Node* solve(int in[],int pre[], int &index, int inorderStart, int inorderEnd, int n,map<int,int>nodeToIndex)
    {
        if(index>n||inorderStart > inorderEnd)
        {
            return NULL;
        }

        int element = pre[index++];
        Node* root = new Node(element);
        int position = nodeToIndex[element];

        //recursive calls
        root->left = solve(in,pre,index, inorderStart, position-1,n,nodeToIndex);
        root->right = solve(in,pre,index, position+1, inorderEnd,n,nodeToIndex);

        return root;
    }
    Node* buildTree(int in[], int pre[], int n)
    {
      
        int preOrderIndex = 0;
        map<int,int> nodeToIndex;
        //create Node to index mapping
      
        createMapping(in,nodeToIndex, n);
      
        Node* ans = solve(in, pre, preOrderIndex, 0,n-1,n,nodeToIndex);
      
        return ans;
    }
};
void inorderTraversal(Node* root)
{
    if(root == NULL)
    {
        return ;
    }

    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}
int main()
{
    Solution obj;
    int in[] = {3,1,4,0,5,2};
    int pre[] = {0,1,3,4,2,5};
    int  n = 6;
    
    Node* ans = obj.buildTree(in, pre, n);
    
    inorderTraversal(ans);   
}