#include<iostream>
using namespace std;

class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data){
        this->data  = data;
        left = NULL;
        right = NULL;
    }
};

bool isBST(BinaryTreeNode<int> *root)
{
    if(root==NULL)
    {
        retrun true;
    }

    if(root->data >= min && root->data <= max)
    {
       bool left = isBST(root->left,min,root->data);
       bool right = isBST(root->right,root->data,max);
       return left && right;
    }
    else {
        return false;
    }

}

bool valideBST(BinaryTreeNode<int> *root )
{
    return isBST(root,INT_MIN,INT_MAX);
}
