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
    public:
    pair<bool,int>isSumTreeFast(Node* root)
    {
        //base case
        if(root->left ==NULL && root->right == NULL)
        {
            pair<bool,int>p = make_pair(true,0);
            return p;
        }
        if(root->left== NULL && root->right== NULL)
        {
            pair<bool,int>p = make_pair(true, root->data);
            return p;
        }


        pair<bool,int> leftAns = isSumTreeFast(root->left);
        pair<bool,int> rightAns = isSumTreeFast(root->right);

        bool isleftSumTree = leftAns.first;
        bool isrightSumTree = rightAns.first;

        int leftSum = leftAns.second;
        int rightSum = rightAns.second;
        bool condn = root->data == leftSum+rightSum;

        pair<bool,int> ans;

        if(isleftSumTree && isrightSumTree &&  condn)
        {
            ans.first = true;
            ans.second = root->data + leftSum + rightSum;
        }
        else{
            ans.first = false;
        }
       // cout<<ans.first<<ans.second<<endl;
        return ans;
        
    }

    bool isSumTree(Node* root)
    {
        return isSumTreeFast(root).first;
    }
};
Node* build(Node *root)
{
    cout<<"Enter the data"<<endl;
    int data;
    cin>>data;

    root = new Node(data);
    if(data == -1)
    {
        return NULL;
    }

    cout<<"Enter the data for left of  "<<data<<endl;
    root->left  = build(root->left);
    cout<<"Enter the data for right of "<<data<<endl;
    root->right = build(root->right);

    return root;
}

void LevelOrderTraversal(Node* root)
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

int main()
{
    Solution obj;
  //  Node* root = NULL;
  //  root = build(root);
   Node* root = new Node(26);
    root->left = new Node(10);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(6);
    root->right->right = new Node(3);

    LevelOrderTraversal(root);
    bool ans = obj.isSumTreeFast(root).first;
    if(ans)
    {
        cout<<"The tree is Sum tree"<<endl;
    }
    else{
        cout<<"The Tree is Not a Sum tree"<<endl;
    }
}
// int main()
// {
//     // build the tree
//     Node* root = new Node(26);
//     root->left = new Node(10);
//     root->right = new Node(3);
//     root->left->left = new Node(4);
//     root->left->right = new Node(6);
//     root->right->right = new Node(3);

//     // print the tree
//     cout << "Level order traversal of the tree: " << endl;
//     LevelOrderTraversal(root);

//     cout<<"hi"<<endl;
//     // check if the tree is a sum tree
//     Solution obj;
//      cout<<"hi"<<endl;
//     bool ans = obj.isSumTree(root);
//      cout<<"hi"<<endl;
//     if(ans)
//     {
//         cout << "The tree is a sum tree" << endl;
//     }
//     else
//     {
//         cout << "The tree is not a sum tree" << endl;
//     }

//     return 0;
// }

