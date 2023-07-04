#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d)
    {
        this -> data = d;
        this ->left = NULL;
        this -> right = NULL;
    }
};

node* buildTree(node* root)
{
    cout<<"Enter the node: "<<endl;
    int data;
    cin>>data;
    root = new node(data);

    if(data == -1)
    {
        return NULL;
    }

    cout<<" enter the data for inserting in left of "<<data<<endl;
    root -> left = buildTree(root-> left);
    cout<<"enter the data for inserting in right of "<<data<<endl;
    root -> right = buildTree(root-> right);
    return root;
}
void levelorderTraversal(node* root)
{
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node*temp = q.front();
        q.pop();
        if(temp == NULL)
        {
            //purana level complete traverse ho chuka hai
            cout<<endl;
            if(!q.empty())
            {
                //queue still has some child nodes
                q.push(NULL);
            }
        }
        else
        {
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

void inorder(node* root)
{
    //base case
    if(root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(node * root)
{
    //base case
    if(root == NULL)
    {
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root)
{
    if(root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
node* display();
int main()
{
    node* root = NULL;
    //creating a tree
    root = buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    //level order
    cout<<"Printing the level order traversal output"<<endl;
    levelorderTraversal(root);
    return 0;
}

















