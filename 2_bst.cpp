#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

bool validate_helper /*1.1 function*/ (Node *root, int min, int max)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data >= min && root->data < max)
    {
        bool left = validate_helper(root->left, min, root->data);
        bool right = validate_helper(root->right, root->data, max);
        bool conformer = (left && right);
        return conformer;
    }
    else
    {
        return false;
    }
}

bool validate_bst /*1.0 function*/ (Node *root)
{
    return validate_helper(root, INT_MIN, INT_MAX);
}

// we are given root of the BST and we need to return the k th smallest element
Node *kthSmallest(Node *root, int &k)
{
    if (root == NULL)
    {
        return NULL;
    }

    Node *left = kthSmallest(root->left, k);
    if (left != NULL)
    {
        return left;
    }
 
    k--;
    if (k == 0)
    {
        return root;
    }

    return kthSmallest(root->right, k);
}

Node *LCAinaBST(Node *root, Node *P, Node *Q)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (P->data > root->data && Q->data > root->data)
    {
        return LCAinaBST(root->right, P, Q);
    }

    if (P->data < root->data && Q->data < root->data)
    {
        return LCAinaBST(root->left, P, Q);
    }

    return root;
}

int main()
{

    return 0;
}