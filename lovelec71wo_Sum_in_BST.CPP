#include<iostream>
using namespace std;

class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void inorder(BinaryTreeNode<int>* root,vector<int> &in)
{
    if(root == NULL)
    {
        return ;
    }

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right,in);
}
{
bool twoSumInBST(BinaryTreeN ode<int>* root,int target)
    vector<int> inorderVal;
    //store inorder ->sorted values
    inorder(root, inorderVal);

    //use two pointer approach to check if pairs exits 
    int i = 0, j = inorderVal.size()-1;

    while(i<j)
    {
        int sum = inorderVal[i] + inorderVal[j];
        if(sum == target)
        {
            return true;    
        }
        else if(sum>target){
            j--;

        }
        else{
            i++;
        }
    }
    return false;
}


































