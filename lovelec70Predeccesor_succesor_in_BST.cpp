#include<iostream>
using namespace std;
template<typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode()
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
};

pair<int,int>predeccesorSuccessor(BinaryTreeNode<int>*root,int key)
{

    //find key
    BinaryTreeNode<int>* temp = root;
    int pred = -1;
    int succ = -1;


    while(temp->data != key)
    {
        if (temp->data>key)
        {
           succ = temp->data;
           temp = temp->left;   
        }
        else{
            pred = temp->data;
            temp = temp->right;
        }
    }

    BinaryTreeNode<int>* leftTree = temp->left;
    //predeccessor ->left subtree ->max
    while(leftTree!= NULL)
    {
        pred = leftTree->data;
        leftTree = leftTree->right;
    }

    BinaryTreeNode<int>* rightTree = temp->right;
    //succsecor -> right subtree -> min
    while(rightTree!= NULL)
    {
        succ = rightTree->data;
        rightTree = rightTree->right;
    }

    pair<int,int> ans = make_pair(pred,succ);
    return ans;
    //return {pred,succ} This will too work



}













