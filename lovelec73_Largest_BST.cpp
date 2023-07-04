#include<iostream>
#include<bits/stdc++.h>
using namespace std;

template<typename T>
class TreeNode{
    public:
    int data;
    TreeNode * left;
    TreeNode * right;

     TreeNode(int data)
     {
        this->data = data;
        left = NULL;
        right = NULL;
     }   

     ~TreeNode()
     {
        if(left)
        {
            delete left;
        }
        if(right)
        {
            delete right;
        }
     }

}
class info{
    public:
    int maxi;
    int mini;
    bool isBST;
    int size;

};

info solve(TreeNode<int>* root, int & ans)
{
    //base case
    if(root==NULL)
    {
        return {INT16_MIN,INT16_MAX,true, 0};
    }

    info left = solve(root->left, ans);
    info right = solve(root->right, ans);

    info currNode;

    currNode.size = left.size+ right.size+1;
    currNode.maxi = max(root->data,right.maxi);
    currNode.mini = min(root->data, left.mini);

    if(left.isBST && right.isBST && (root->data >left.maxi && root->data <right.mini))
    {
        currNode.isBST = true;
    }
    else{
        currNode.isBST  =  false;

    }
    //answer update

        if(currNode.isBST)
        {
            ans = max(ans, currNode.size);
        }

        return  currNode;
}

int largestBST(TreeNode<int>* root)
{
    int maxsize = 0;
    info temp= solve(root,maxsize);
    return maxsize;
}
