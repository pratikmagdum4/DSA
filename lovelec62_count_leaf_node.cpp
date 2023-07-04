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

    void inorder(BinaryTreeNode<int> *root,int &count)
    {
        //if tree is empty
        if(root == NULL)
        {
            return;
        }

        inorder(root->left,count);
        //check leaf node
        if(root->left == NULL && root->right == NULL)
        {
            count++;
        }
        inorder(root->right,count);
    }
    int noOfLeafNodes(BinaryTreeNode<int> *root)
    {
        int count = 0;
        inorder(root,count);
        return count;
    }

    BinaryTreeNode<int>* build(BinaryTreeNode<int>* root)
    {
        cout<<"Enter the node"<<endl;
        int data;
        cin>>data;
        root = new BinaryTreeNode<int>(data);

        if(data == -1)
        {
            return NULL;
        }

        cout<<"Enter the left of the "<<data<<endl;
        root->left =  build(root->left);
        cout<<"Enter the right of the "<<data<<endl;
        root->right =  build(root->right);
    }
    void levelOrderTraversal(BinaryTreeNode<int>* root)
    {
        queue<BinaryTreeNode<int>*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
            BinaryTreeNode<int>* temp = q.front();
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
        BinaryTreeNode<int>*root = NULL;
        root =  build(root);
        levelOrderTraversal(root);
        int ans = noOfLeafNodes(root);
        cout<<"The number of leaf nodes is"<<ans<<endl;
        //1 3 5 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    }
    