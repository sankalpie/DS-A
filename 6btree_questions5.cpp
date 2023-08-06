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
        this->right = NULL;
        this->left = NULL;
    }
};

Node *build_tree(Node *root)
{
    cout << "enter data" << endl;
    int data;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    root = new Node(data);
    cout << "Enter data for left of " << data << endl;
    root->left = build_tree(root->left);
    cout << "Enter data for right of " << data << endl;
    root->right = build_tree(root->right);
    return root;
}

// you will be given inorder as well as preorder traversal and you must return back postorder

// inorder (LNR)
// preorder (NLR)

int find_positionOfNode_in_inorder(int iska_node_bana, int in[], int n)
{

    for (int i = 0; i < n; i++)
    {
        if (in[i] == iska_node_bana)
        {
            return i;
        }
    }
    return -1;
}

Node *solve_in_pre(int in[], int pre[], int &index, int inorder_start, int inorder_end, int n)
{
    if (index >= n || inorder_start > inorder_end)
    {
        return NULL;
    }

    int iska_node_bana = pre[index++]; // pre order ka jo starting index hai uska node bana do aur index ko ek bhadha do
    Node *root = new Node(iska_node_bana);

    int pos_in_inorder = find_positionOfNode_in_inorder(iska_node_bana, in, n);

    // ab recursive call
    root->left = solve_in_pre(in, pre, index, inorder_start, pos_in_inorder - 1, n);
    root->right = solve_in_pre(in, pre, index, pos_in_inorder + 1, inorder_end, n);

    return root;
}

Node *build_from_in_pre(int in[], int pre[], int n) // n is the size of tree
{
    int index = 0;
    Node *ans = solve_in_pre(in, pre, index, 0, n - 1, n);
    return ans;
}

int main()
{

    return 0;
}

//
//
//
//
//
//
//
//
//
//

// int find_positionOfNode_in_inorder(int iska_node_bana, int in[], int n)
// {

//     for (int i = 0; i < n; i++)
//     {
//         if (in[i] == iska_node_bana)
//         {
//             return i;
//         }
//     }
//     return -1;
// }

void create_mapping(int in[], unordered_map<int, int> &nodeToIndex, int n)
{
    for (int i = 0; i < n; i++)
    {
        nodeToIndex[in[i]] = i;
    }
}

Node *solve_in_pre(   int in[], int pre[], int &index, int inorder_start, int inorder_end, int n, unordered_map<int, int> &nodeToIndex  )
{
    if (index >= n || inorder_start > inorder_end)
    {
        return NULL;
    }

    int iska_node_bana = pre[index++]; // pre order ka jo starting index hai uska node bana do aur index ko ek bhadha do
    Node *root = new Node(iska_node_bana);

    // int pos_in_inorder = nodeToIndex[iska_node_bana];

    int pos_in_inorder = -1;
    for (int i = inorder_start; i <= inorder_end; i++)
    {
        if (in[i] == iska_node_bana)
        {
            pos_in_inorder = i;
            break;
        }
    }

    // ab recursive call

    root->left = solve_in_pre(in, pre, index, inorder_start, pos_in_inorder - 1, n, nodeToIndex);
    root->right = solve_in_pre(in, pre, index, pos_in_inorder + 1, inorder_end, n, nodeToIndex);

    return root;
}

Node *buildTree(int in[], int pre[], int n)
{
    // Code here
    int index = 0;
    unordered_map<int, int> nodeToIndex;
    create_mapping(in, nodeToIndex, n);
    Node *ans = solve_in_pre(in, pre, index, 0, n - 1, n, nodeToIndex);
    return ans;
}






/*
















*/

void create_mapping(int in[], unordered_map<int, int> &nodeToIndex, int n)
{
    for (int i = 0; i < n; i++)
    {
        nodeToIndex[in[i]] = i;
    }
}

Node* solve_in_post(int in[], int post[], int &index, int inorder_start, int inorder_end, int n, unordered_map<int, int> &nodeToIndex)
{
    if (index < 0 || inorder_start > inorder_end)
    {
        return NULL;
    }

    int iska_node_bana = post[index--]; // pre order ka jo starting index hai uska node bana do aur index ko ek bhadha do
    Node *root = new Node(iska_node_bana);

    // int pos_in_inorder = nodeToIndex[iska_node_bana];

    int pos_in_inorder = -1;
    for (int i = inorder_start; i <= inorder_end; i++)
    {
        if (in[i] == iska_node_bana)
        {
            pos_in_inorder = i;
            break;
        }
    }

    // ab recursive call

    root->right = solve_in_pre(in, post, index, pos_in_inorder + 1, inorder_end, n, nodeToIndex);
    root->left = solve_in_pre(in, post, index, inorder_start, pos_in_inorder - 1, n, nodeToIndex);

    return root;
}


//ab bhai aayega inorder, postorder se banao preorder
Node * tree_in_post(int in[],int post[],int n)
{
    // Code here
    int index = n-1;
    unordered_map<int, int> nodeToIndex;
    create_mapping(in, nodeToIndex, n);
    Node *ans = solve_in_post(in, post, index, 0, n - 1, n, nodeToIndex);
    return ans;
}