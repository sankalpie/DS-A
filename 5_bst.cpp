#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *right;
    Node *left;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// largest BST in a binary tree
// return the size (how many number of nodes are there in that BST) of the largest BST in a BT
// O(n) time

// ek vector mein 4 cheezein hongi -- maximum out of left subtree, minimum out of right subtree, boolean showing if until this node is it a BST or not, and an integer showing the number of nodes included in the BST

vector<int> largestBST_helper(Node *root, int &maxSize)
{
    if (root == NULL)
    {
        vector<int> base_case_vector = {INT_MIN, INT_MAX, true, 0};
        return base_case_vector;
    }

    vector<int> v_left = largestBST_helper(root->left, maxSize);
    vector<int> v_right = largestBST_helper(root->right, maxSize);


    bool is_bst = false;
    if (v_left[2] && v_right[2] && (root->data > v_left[0] && root->data < v_right[1] /*root ka data left subtree ke max se bhi bada aur right subtree ke minimum se bhi chota*/))
    {
        is_bst = true;
    }

    vector<int> current_node_ka_vector = {max(root->data, v_right[0]), min(root->data, v_left[1]), is_bst, v_left[3] + v_right[3] + 1};

    if (is_bst)
    {
        maxSize = max(maxSize, current_node_ka_vector[3]);
    }

    return current_node_ka_vector;
}

int largestBST(Node *root)
{
    int maxSize = 0; // the size of the largest BST that we have to return
    vector<int> temp = largestBST_helper(root, maxSize);

    return maxSize;
}

int main()
{

    return 0;
}