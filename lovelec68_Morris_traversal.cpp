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
void MorrisTraversal(Node* root)
{
    while(root)
    {
    //if the left child is null,print the current node, move to the right child
        if(root->left == NULL)
        {
            cout<<root->data<<" ";
            root = root->right;
        }    
        else{
            // find inorder predecessor
            Node* current = root->left;
            while(current->right && current->right != root)
                current = current->right;
            //if the right child of inorder predecessor already points to this node
            if(current->right == root)
            {
                current->right = NULL;
                root= root->right;
            }
            //if right child doesn't point to this node then print this node and make right child point to this node
            else{
                cout<<root->data<<" ";
                current->right = root;
                root=root->left;
            }
        }
    }
}
//Function for standard preorder traversal 
void preorder(Node* root)
{
    if(root)
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
    else{
        return;
    }
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->left->right = new Node(3);
    root->left->left->right->left = new Node(4);
    root->right = new Node(7);
    root->right->right = new Node(8);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);

    MorrisTraversal(root);
    cout<<endl;
    preorder(root); 
}