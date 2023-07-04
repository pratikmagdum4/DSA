#include<iostream>
using namespace std;

template<typename T>
class TreeNode {
    public:
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if(left)
            delete left;
        if(right)
            delete right;
    }
};

TreeNode<int>* LCAinBST(TreeNode<int>*root, TreeNode<int>* P,TreeNode<int>*Q)
{
// RECURSIVE SOLUTION


    //base case
    if(root == NULL)
    {
        return NULL;
    }

    if(root->data < P->data && root->data < Q->data)
    {
        return LCAinBST(root->right,P,Q);
    }

    if(root->data < P->data && root->data < Q->data)
    {
        return LCAinBST(root->left,P,Q);
    }

//    if((root->data > P->data && root->data < Q->data) || (root->data < P->data && root->data > Q->data))
//    {
//     return root;
//    }
    return root;


    //ITERATIVE SOLUTION
/*
    while(root!= NUll)
    {
        if(root->data < P->data && root->data < Q->data)
            root = root->right;
        else if(root->data < P->data && root->data < Q->data)
             root =root->left;
        else{
            return root;
        }
        
    }
    */
}