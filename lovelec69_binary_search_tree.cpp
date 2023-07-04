#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* insertIntoBST(Node* &root, int d)
{
    //base case
    if(root == NULL)
    {
        root = new Node(d);
        return root;
    }

    if(d > root->data)
    {
        //right part me insert karna h
        root->right = insertIntoBST(root->right,d);
    }
    else{
        //left part me insert karna hai
        root->left = insertIntoBST(root->left,d);
    }
    return root;
}

Node* minVal(Node* root)
{
    Node* temp = root;

    while(temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

Node* maxVal(Node* root)
{
    Node* temp = root;

    while(temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}

Node* deleteFromBST(Node* root, int val)
{
    //base case
    if(root == NULL)
    {
        return root;
    }
    if(root->data == val){
        //0 child
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        //1 child
        //left child
        if(root->left != NULL && root->right == NULL)
        {
        Node *temp = root->left;
        delete root;
        return temp;
        }
        //right child
        if(root->left == NULL && root->right != NULL)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        //2 child 
        if(root->left!= NULL && root->right != NULL)
        {
            int mini = minVal(root->right) != NULL;
            root->data = mini;
            root->right = deleteFromBST(root->right,mini);
            return root;
        }
    }
    else if(root->data > val)
    {
        //left part me jao
        root->left = deleteFromBST(root->left, val);
        return root;
    }
    else if(root->data<val)
    {
        //right part me jao
        root->right = deleteFromBST(root->right, val);
        return root;
    }
}
void takeInput(Node* &root)
{
    int data;
    cin>>data;

    while(data != -1)
    {
        root = insertIntoBST(root,data);
        cin>>data;
    }
}

void levelOrderTraversal(Node* &root)
{
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty())
    {
        Node* temp = q.front();
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

void deleteTree(Node* &root)
{
    if(root == NULL)
    {
        return;
    }

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    root = NULL;
}

int main()
{
    Node* root = NULL;
    cout<<"Enter the data to create BST "<<endl;
    takeInput(root);
    cout<<"Printing the BST "<<endl;
    levelOrderTraversal(root);
    deleteFromBST(root,4);
    cout<<endl;
    levelOrderTraversal(root);

    deleteTree(root);

}
