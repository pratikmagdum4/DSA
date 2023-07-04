#include<iostream>
using namespace std;

template <typename> T
class TreeNode{

    public:
    int data;
    TreeNode<T>* left;
    TreeNode<T>* right;

    TreeNode(int data)
    {
        this->data = data;
        left  = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if(left)
            delete left;
        if(right)
            delete right;
    }
};


TreeNode<int>* inoder(TreeNode<int>* root, vector<int> in)
{
    if(root == NULL)
    {
        return ;
    }
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right, in);

}

TreeNode<int>* inorderToBST(int s, int e, vector<int> &in )//Passing by reference is very important
{
    //base case 
    if(s>e)
    {
        return NULL;
    }

    int mid = (s+e)/2;

    TreeNode<int>* root = new TreeNode<int>(in[mid]);
    root->left = inorderToBST(s,mid-1,in);
    root->right = inorderToBST(mid+1,e ,in);
    return root;
}
TreeNode<int>* balancedBST(TreeNode<int>* root)
{
        vector<int>inorderVal;
        //store inoder -> sorted values
        inorder(root,inorderVal);

    return inorderToBST(0,inoderVal.size()-1,in);  
}
