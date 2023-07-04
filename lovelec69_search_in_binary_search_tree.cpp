#include<iostream>
#include<bits/stdc++.h>
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
};
template<typename T>
bool searchInBST(BinaryTreeNode<T> *root, T x)
{
    BinaryTreeNode<T> *temp = root;

    while(temp != NULL)
    {
        if(root->data == x)
        {
            return true;
        }
        if(root->data >x)
        {
            temp = temp->left;
        }
        if(root->data <x)
        {
            temp = temp->right;
        }
    }
    return false;
}

int main()
{
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(4);
    bool ans = searchInBST(root,5);
    if(ans)
    {
        cout<<"yes present"<<endl;
    }
    else{
        cout<<"no not present"<<endl;
    }
    return 0;
}


