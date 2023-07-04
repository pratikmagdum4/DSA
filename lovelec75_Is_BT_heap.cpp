#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
class Solution{
    public:
    int countNodes(struct Node* root)
    {
        //base case
        if(root== NULL)
        {
            return 0;
        }
        int ans = 1+ countNodes(root->left) + countNodes(root->right);
        return ans;
    }
    bool isCBT(struct Node* root, int index , int cnt)
    {
        if(root==NULL)
        {
                return true;
        }
        if(index>cnt)
        {
            return false;
        }
        else{
            bool left = isCBT(root->left, 2*index+1,cnt);
            bool right = isCBT(root->right, 2*index+2,cnt);
            return (left&&right);   
        }
    }
    bool isMaxorder(struct Node* root)
    {
        //leaf Node
        if(root->left == NULL && root->right== NULL)
        {
            return true;
        }
        if(root->right== NULL)
        {
            return (root->data > root->left->data);
        }
        else{
            return (root->data > root->left->data && root->data >root->right->data&&
            isMaxorder(root->left)&&isMaxorder(root->right));
        }
    }
    bool isHeap(struct Node* root)
    {
        int index = 0;
        int totalCount = countNodes(root);
        if(isCBT(root,index, totalCount)&& isMaxorder(root))
        {
            return true;
        }
        else{
            return false;
        }
    }
};
int main()
{
    Solution s;
    Node* root = new Node(70);
    root->left = new Node(61);
    root->left->left = new Node(45);
    root->left->right = new Node(50);
    root->right = new Node(55);

    bool ans = s.isHeap(root);
    if(ans)
    {
        cout<<"It is heap"<<endl;
    }
    else{
        cout<<"It is not heap"<<endl;
    }
}