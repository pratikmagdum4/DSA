// #include <iostream>
// #include <vector>
// #include <map>
// using namespace std;

// struct Node {
//     int data;
//     Node* left, *right;
// };

// // Function to create a new binary tree node
// Node* newNode(int key) {
//     Node* temp = new Node;
//     temp->data = key;
//     temp->left = temp->right = NULL;
//     return temp;
// }

// // Function to perform diagonal traversal of binary tree
// void diagonalTraversal(Node* root, int d, map<int, vector<int>> &diagonalMap) {
//     if (!root) return;

//     diagonalMap[d].push_back(root->data);

//     diagonalTraversal(root->left, d+1, diagonalMap);
//     diagonalTraversal(root->right, d, diagonalMap);
// }

// int main() {
//     Node* root = newNode(8);
//     root->left = newNode(3);
//     root->right = newNode(10);
//     root->left->left = newNode(1);
//     root->left->right = newNode(6);
//     root->right->right = newNode(14);
//     root->right->right->left = newNode(13);
//     root->left->right->left = newNode(4);
//     root->left->right->right = newNode(7);

//     map<int, vector<int>> diagonalMap;

//     diagonalTraversal(root, 0, diagonalMap);

//     cout << "Diagonal Traversal of Binary Tree:" << endl;
//     for (auto it : diagonalMap) {
//         for (auto i : it.second) {
//             cout << i << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }
#include<iostream>
#include<bits/stdc++.h>
#include<map>
#include<vector>
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

class Solution{
    public:
    void solve(Node* root,int depth, map<int,vector<int> >&diagonalMap)
    {
        if(root == NULL)
        {
            return;
        }
        diagonalMap[depth].push_back(root->data);

        solve(root->left,depth+1,diagonalMap);
        solve(root->right,depth,diagonalMap);
    }
    public:
    void diagonalTraversal(Node* root)
    {
        map<int,vector<int> >diagonalMap;
        solve(root,0,diagonalMap);
        for(auto i:diagonalMap)
        {
            for(auto it: i.second)
            {
                cout<<it<<" ";
            }
            cout<<endl;
        }
    }
};
int main()
{
    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);
    Solution obj;
    obj.diagonalTraversal(root);
    return 0;
}

