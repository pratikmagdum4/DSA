#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode() {
        if (left) {
            delete left;
        }
        if (right) {
            delete right;
        }
    }
};

void inorder(TreeNode<int>* root, vector<int>& in) {
    if (root == NULL) {
        return;
    }
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

vector<int> mergeArrays(vector<int>& a, vector<int>& b) {
    vector<int> ans(a.size() + b.size());
    int i = 0, j = 0, k = 0;

    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            ans[k++] = a[i++];
        }
        else {
            ans[k++] = b[j++];
        }
    }

    while (i < a.size()) {
        ans[k++] = a[i++];
    }

    while (j < b.size()) {
        ans[k++] = b[j++];
    }

    return ans;
}

TreeNode<int>* inorderToBST(int s, int e, vector<int>& in) {
    //base case
    if (s > e) {
        return NULL;
    }

    int mid = (s + e) / 2;
    TreeNode<int>* root = new TreeNode<int>(in[mid]);
    root->left = inorderToBST(s, mid - 1, in);
    root->right = inorderToBST(mid + 1, e, in);
    return root;
}

void convertIntoSortedDLL(TreeNode<int>* root, TreeNode<int>*& head) {
    //base case
    if (root == NULL) {
        return;
    }

    convertIntoSortedDLL(root->right, head);

    root->right = head;
    if (head != NULL)
        head->left = root;

    head = root;

    convertIntoSortedDLL(root->left, head);
}

TreeNode<int>* mergeLinkedList(TreeNode<int>* head1, TreeNode<int>* head2) {
    TreeNode<int>* head = NULL;
    TreeNode<int>* tail = NULL;

    while (head1 != NULL && head2 != NULL) {
        if (head1->data < head2->data) {
            if (head == NULL) {
                head = head1;
                tail = head;
                head1 = head1->right;
            }
            else {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else {
            if (head == NULL) {
                head = head2;
                tail = head;
                head2 = head2->right;
            }
            else {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    while (head1 != NULL) {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    while (head2 != NULL) {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }

    tail->right = NULL;

    return head;
}

int countNodes(TreeNode<int>* head) {
    int cnt = 0;
    TreeNode<int>* temp = head;
    while (temp != NULL) {
        cnt++;
        temp = temp->right;
    }

    return cnt;
}

TreeNode<int>* sortedLLToBST(TreeNode<int>*& head, int n) {
    //base case
    if (n <= 0 || head == NULL) {
        return NULL;
    }

    TreeNode<int>* left = sortedLLToBST(head, n / 2);

    TreeNode<int>* root = head;
    root->left = left;
    head = head->right;
    root->right = sortedLLToBST(head, n - n / 2 - 1);
    return root;
}

TreeNode<int>* mergeBST(TreeNode<int>* root1, TreeNode<int>* root2) {
    //step1: store inorder
    vector<int> bst1, bst2;
    inorder(root1, bst1);
    inorder(root2, bst2);
    //step2: Merged both sorted arrays
    vector<int> mergeArray = mergeArrays(bst1, bst2);

    //step3: use merged inorder array to build BST
    int s = 0, e = mergeArray.size() - 1;
    return inorderToBST(s, e, mergeArray);
}

int main() {
    TreeNode<int>* root1 = new TreeNode<int>(3);
    root1->right = new TreeNode<int>(35);
    root1->left = new TreeNode<int>(33);
    root1->left->left = new TreeNode<int>(32);
    root1->left->left->right = new TreeNode<int>(36);
    root1->right->left = new TreeNode<int>(37);
    root1->right->right = new TreeNode<int>(23);

    TreeNode<int>* root2 = new TreeNode<int>(12);
    root2->right = new TreeNode<int>(34);
    root2->left = new TreeNode<int>(54);
    root2->left->left = new TreeNode<int>(45);
    root2->left->right = new TreeNode<int>(56);
    root2->right->left = new TreeNode<int>(64);
    root2->right->right = new TreeNode<int>(38);

    TreeNode<int>* mergedRoot = mergeBST(root1, root2);

    // Print the merged BST (in-order traversal)
    vector<int> inorderTraversal;
    inorder(mergedRoot, inorderTraversal);
    for (int i = 0; i < inorderTraversal.size(); i++) {
        cout << inorderTraversal[i] << " ";
    }
    cout << endl;

    // Clean up the allocated memory
    delete mergedRoot;

    return 0;
}
