#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node * /*first function*/ build_tree(node *root)
{
    cout << "Enter data" << endl;
    int data;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    root = new node(data);

    cout << "Enter data for left of " << data << endl;
    root->left = build_tree(root->left);
    cout << "Enter data for right of " << data << endl;
    root->right = build_tree(root->right);

    return root;
}

void /*second function*/ level_order(node *root)
{
    queue<node *> q1;
    q1.push(root);
    q1.push(NULL);

    while (!q1.empty())
    {
        node *temp = q1.front();
        q1.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q1.empty())
            {
                q1.push(NULL);
            }
        }
        else if (temp != NULL)
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q1.push(temp->left);
            }

            if (temp->right)
            {
                q1.push(temp->right);
            }
        }
    }
}

void /*third function*/ inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// node * /*fourth function*/ tree_from_level(node *root)
// {
//     queue<node *> q1;
//     cout << "Enter data " << endl;
//     int data;
//     cin >> data;
//     root = new node(data);

//     q1.push(root);

//     while (!q1.empty())
//     {
//         node *temp = q1.front();
//         q1.pop();

//         cout << "Now enter left node for " << temp->data << endl;
//         int leftdata;
//         cin >> leftdata;
//         if (leftdata != -1)
//         {
//             temp->left = new node(leftdata);
//             q1.push(temp->left);
//         }
//         cout << "Now enter right node for " << temp->data << endl;
//         int rightdata;
//         cin >> rightdata;
//         if (rightdata != -1)
//         {
//             temp->right = new node(rightdata);
//             q1.push(temp->right);
//         }
//     }
// }

int /*fifth function*/ find_height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = find_height(root->left);
    int right = find_height(root->right);
    int height = max(left, right) + 1;

    return height;
}

int /*sizth function*/ find_diameter(node *root)
{
    // longest number of nodes between 2 end nodes

    if (root == NULL)
    {
        return 0;
    }
    int left_only = find_diameter(root->left);
    int right_only = find_diameter(root->right);
    int through_root = find_height(root->left) + find_height(root->right) + 1;

    return max(through_root, max(right_only, left_only));
}

pair<int, int> /*seventh function*/ find_diameter_fast(node *root)
{
    if (root == NULL)
    {
        return {0, 0};
    }
    pair<int, int> left_only_pair = find_diameter_fast(root->left);
    pair<int, int> right_only_pair = find_diameter_fast(root->right);

    int left_only = left_only_pair.first; // pair ke first me diameter store hota hai
    int right_only = right_only_pair.first;
    int through_middle = left_only_pair.second + right_only_pair.second + 1; // pair ke second me height store hoti hai

    return {(max(through_middle, max(left_only, right_only))), (max(left_only_pair.second, right_only_pair.second) + 1)};
}

bool /*eighth function*/ is_balanced(node *root)
{
    if (root == NULL)
    {
        return true;
    }

    bool left_balanced = is_balanced(root->left);
    bool right_balanced = is_balanced(root->right);
    bool third_condition;

    if (abs(find_height(root->left) - find_height(root->right)) <= 1)
    {
        third_condition = true;
    }
    else
    {
        third_condition = false;
    }

    if (left_balanced && (right_balanced && third_condition))
    {
        return true;
    }

    return false;
}

pair<bool, int> /*ninth function*/ is_balanced_fast(node *root)
{
    if (root == NULL)
    {
        return {true, 0}; // first element contains wether it is balanced or not and second element contains the height difference
    }

    pair<bool, int> left_pair = is_balanced_fast(root->left);
    pair<bool, int> right_pair = is_balanced_fast(root->right);

    if (left_pair.first && right_pair.first && (abs(left_pair.second - right_pair.second) <= 1))
    {
        return {true, max(left_pair.second, right_pair.second) + 1};
    }
    else
    {
        return {false, max(left_pair.second, right_pair.second) + 1};
    }
}

bool /*tenth function*/ is_identical(node *root1, node *root2)
{
    if (root1== NULL && root2==NULL)
    {
        return true;
    }
    if(root1 == NULL && root2 != NULL) 
    {
        return false;
    }
    if(root1 != NULL && root2 == NULL)
    {
        return false;
    }

    // if (root1->data != root2->data)
    // {
    //     return false;
    // }
    

    // is_identical(root1->left, root2->left);
    // is_identical(root1->right, root2->right);

    if(is_identical(root1->left,root2->left) && is_identical(root1->right,root1->right) && (root1->data == root2->data) )
    {
        return true;
    }
    else
    {
        return false;
    }
    // return true;
}

pair<bool,int> /*eleventh function*/ is_sum_tree(node * root)
{
    if(root==NULL)
    {
        return {true,0}; //first element of pair shows is it a sum tree and second element is pair shows its sum
    }
    if(root->left==NULL && root->right==NULL)
    {
        return {true,root->data};
    }
    pair<bool,int> left_pair=is_sum_tree(root->left);
    pair<bool,int> right_pair=is_sum_tree(root->right);

    if( left_pair.first && right_pair.first && (root->data==left_pair.second+right_pair.second) )
    {
        return {true, 2*(root->data) };
    }
    else
    {
        return {false,root->data+left_pair.second+right_pair.second};
    }
}

int main()
{
    node *root = NULL;

    root = build_tree(root); /*first building tree*/

    cout << "\nNOW levelorder" << endl;
    level_order(root); /*second level order*/

    cout << "\nNow inorder" << endl;
    inorder(root); /*third inorder*/

    cout << "\nNow find_height" << endl;
    cout << find_height(root) << endl; /*fifth find_height*/

    cout << "\nNow find_diameter" << endl;
    cout << find_diameter(root) << endl;

    cout << "\nNow find_diameter_fast" << endl;
    cout << find_diameter_fast(root).first << endl;

    cout << "\nNow is_balanced" << endl;
    cout << is_balanced(root) << endl;

    cout << "\nNow is balanced fast" << endl;
    cout << is_balanced_fast(root).first << endl;

    cout << "\nNow is_identical" << endl;
    // cout << "But before that you need to enter one more tree" << endl;
    // node *root2 = build_tree(root2);

    cout << is_identical(root, root);

    return 0;
}
// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

//is_identical
//1 2 4 -1 -1 -1 3 5 -1 -1 -1