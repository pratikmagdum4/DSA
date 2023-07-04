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
    void createMapping(map<int,int> &nodeToIndex,int in[],int n)
    {
        for(int i = 0; i<n; i++)
        {
            nodeToIndex[in[i]] = i;
        }
    }
    Node* solve(int in[], int post[], int &index, int inorderStart, int inorderEnd, int n, map<int,int>nodeToIndex)
    {
        if(index < 0|| inorderStart > inorderEnd)
        {
            return NULL;
        }
        int element = post[index--];
        int position = nodeToIndex[element];
        Node* root = new Node(element);
        root->left = solve(in,post,index,inorderStart,position-1,n,nodeToIndex);
        root->right = solve(in,post,index,position+1,inorderEnd,n,nodeToIndex);

        return root;
    }
    Node* buildTree(int in[], int post[], int n)
    {
        int postposition = n-1;
        map<int,int> nodeToIndex ;
        createMapping(nodeToIndex, in, n);
        Node* ans =  solve(in, post, postposition,0,n-1,n,nodeToIndex);
        return ans;
    }
};
void inorderTraversal(Node* root)
{
    if(root==NULL)
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
    int post[] = {0,1,3,4,2,5};
    int  n = 6;
    Node* ans = obj.buildTree(in, post, n);
    inorderTraversal(ans);   
}