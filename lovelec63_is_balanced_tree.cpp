#include<iostream>
#include<bits/stdc++.h>
#include<limits.h>
using namespace std;


struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution{
    private:
    int Height(Node* root)
    {
        if(root == NULL){
            return 0;
        }

        int left = Height(root->left);
        int right = Height(root->right);
        int ans = max(left , right)+1;

        return ans;

    }
    public:
   bool isBalanced(Node* root)
    {
        //base case
        if(root == NULL)
        {
            return true;
        }

        bool left =  isBalanced(root->left);
        bool right = isBalanced(root->right);
        bool diff = abs(Height(root->left)- Height(root->right))<=1;
        if(left&&right&&diff)
        {
            return true;
        }
        else{
            return false;
        }
    }
    // bool isBalanced(Node* root)
    // {
    //     return 
    // }

};
Node* build(Node* root)
{
    cout<<"enter the data"<<endl;
    int data;
    cin>>data;
    root = new Node(data);
    if(data == -1)
    {
        return NULL;
    }
    cout<<"Enter data to the left of "<<data<<endl;
    root->left = build(root->left);
    cout<<"Enter data to the right of "<<data<<endl;
    root->right = build(root->right);
    return root;
}
void levelOrderTraversal(Node* root)
{
    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        if(temp==NULL)
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

    Solution obj;
    Node* root = NULL;
    root = build(root);

    levelOrderTraversal(root);
    bool ans = obj.isBalanced(root);
   if(ans)
   {
    cout<<"It is Balanced"<<endl;
   }
   else{
    cout<<"It is not Balanced"<<endl;
   }
}