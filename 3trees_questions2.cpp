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
        left = NULL;
        right = NULL;
    }
};

Node *build_tree(Node *root)
{
    cout << "Enter data" << endl;
    int data;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    Node *temp = new Node(data);
    temp->left = build_tree(temp->left);
    temp->right = build_tree(temp->right);
}

vector<int> /*first function*/ zig_zag_traversal(Node *root)
{
    vector<int> result;
    if (root == NULL)
    {
        return result;
    }

    queue<Node *> q1;
    q1.push(root);

    bool left_to_right = true;

    while (!q1.empty())
    {
        vector<int> ans(q1.size());
        // process a level
        for (int i = 0; i < q1.size(); i++)
        {
            Node *front_Node = q1.front();
            q1.pop();

            int index = left_to_right ? i : q1.size() - i - 1;
            ans[index] = front_Node->data;
            if (front_Node->left)
            {
                q1.push(front_Node->left);
            }
            if (front_Node->right)
            {
                q1.push(front_Node->right);
            }
        }

        left_to_right = !(left_to_right);

        for (auto i : ans)
        {
            result.push_back(i);
        }
    }

    return result;
}

vector<int> /*second function*/ boundary_traversal(Node *root)
{
    vector<int> anus;

    if (root == NULL)
    {
        return anus;
    }

    anus.push_back(root->data);

    // traverse the left subtree
    traverse_left(root->left, anus);

    // traverse the leaf nodes, the leaf nodes occur in the left as well as right subtree
    traverse_leaf(root->left, anus);
    traverse_leaf(root->right, anus);

    // traverse the right subtree
    traverse_right(root->right, anus);
}

void /*second_1_function*/ traverse_left(Node *root, vector<int> &anus)
{
    if ((root == NULL) || (root->right == NULL && root->left == NULL))
    {
        return;
    }

    anus.push_back(root->data);

    if (root->left)
    {
        traverse_left(root->left, anus);
    }
    else
    {
        traverse_left(root->right, anus);
    }
}

void /*second_2_function*/ traverse_leaf(Node *root, vector<int> &anus)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        anus.push_back(root->data);
        return;
    }

    traverse_leaf(root->left, anus);
    traverse_leaf(root->right, anus);
}

void /*second_3_function*/ traverse_right(Node *root, vector<int> &anus)
{
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
    {
        return;
    }
    if (root->right)
    {
        traverse_right(root->right, anus);
    }
    else
    {
        traverse_right(root->left, anus);
    }

    anus.push_back(root->data);
}

vector<int> /*third function*/ vertical_order_traversal(Node *root)
{
    // create the data structures needed for this question
    map<int, map<int, vector<int>>> nodes;
    queue<pair<Node *, pair<int, int>>> q1; // the pair inside the queue shows Horizontal_distance and level
    vector<int> ansur;

    // base case
    if (root == NULL)
    {
        return ansur;
    }

    // insert the root into the queue
    q1.push({root, {0, 0}}); // root has HD as 0 and level also 0

    while (!q1.empty())
    {
        // remove the front element from the queue
        pair<Node *, pair<int, int>> temp = q1.front();
        q1.pop();
        // jo front element nikala hai uska disection karo aur front node, Horizontal_distance, Level_number nikalo
        Node *front_node = temp.first;
        int HD = temp.second.first;
        int level_number = temp.second.second;

        // map mein ek entry create karo for the node we are currently located at
        nodes[HD][level_number].push_back(front_node->data);

        // ab queue me entry karoge
        if (front_node->left)
        {
            q1.push({front_node->left, {HD - 1, level_number + 1}});
        }
        if (front_node->right)
        {
            q1.push({front_node->right, {HD + 1, level_number + 1}});
        }
    }

    // ab bas inn for loops se hum apna ansur vector bana rahe hain
    map<int, map<int, vector<int>>>::iterator ite1;
    for (ite1 = nodes.begin(); ite1 != nodes.end(); ite1++)
    {
        map<int, vector<int>>::iterator ite2;

        for (ite2 = ((*ite1).second).begin(); ite2 != (*ite1).second.end(); ite2++)
        {
            for (int i = 0; i < (*ite2).second.size(); i++)
            {
                ansur.push_back((*ite2).second[i]);
            }
        }
    }

    return ansur;
}

vector<int> /*fourth function*/ top_view(Node *root)
{
    // required data structures bana lo
    vector<int> ansur;
    map<int, int> top_node;      // horizontal distance aur konsa node hai uskay data ka map banaya hai
    queue<pair<Node *, int>> q1; // ye int mein store hoga Horizontal Distance

    // base case
    if (root == NULL)
    {
        return ansur;
    }

    // map<int,int>top_node; //horizontal distance aur konsa node hai uskay data ka map banaya hai
    // queue<pair<Node *,int>> q1; //ye int mein store hoga Horizontal Distance

    // root ko push kardo queue mein
    q1.push({root, 0});

    while (!q1.empty())
    {
        // front wala element nikaal lo aur uska disection kardo
        pair<Node *, int> temp = q1.front();
        q1.pop();
        Node *front_node = temp.first;
        int HD = temp.second;

        // ab hum apni condition likhenge ki agar for any specific HD there is a value present then we do nothing
        // agar HD naam ko koi key nahi mili then we add that to the map
        if (top_node.find(HD) == top_node.end())
        {
            top_node[HD] = front_node->data;
        }

        // ye hi done steps (front_node->left) aur (front_node->right) hamne upar wale function me bhi kiye hain
        if (front_node->left)
        {
            q1.push({front_node->left, HD - 1});
        }
        if (front_node->right)
        {
            q1.push({front_node->right, HD + 1});
        }
    }

    map<int, int>::iterator ite1; // contains HD and top_node ka data

    for (ite1 = top_node.begin(); ite1 != top_node.end(); ite1++)
    {
        ansur.push_back((*ite1).second);
    }

    return ansur;
}

vector<int> /*fifth function*/ bottom_view(Node *root)
{
    vector<int> ansur;
    map<int, int> top_node;      // horizontal distance aur konsa node hai uskay data ka map banaya hai
    queue<pair<Node *, int>> q1; // ye int mein store hoga Horizontal Distance

    // base case
    if (root == NULL)
    {
        return ansur;
    }

    // map<int,int>top_node; //horizontal distance aur konsa node hai uskay data ka map banaya hai
    // queue<pair<Node *,int>> q1; //ye int mein store hoga Horizontal Distance

    // root ko push kardo queue mein
    q1.push({root, 0});

    while (!q1.empty())
    {
        // front wala element nikaal lo aur uska disection kardo
        pair<Node *, int> temp = q1.front();
        q1.pop();
        Node *front_node = temp.first;
        int HD = temp.second;

        //ye upar wala hi code hai, the only difference is that we don't even need to check any condition
        //jo bhi mila usko map mein daal diya

        // if (top_node.find(HD) == top_node.end())
        // {
            top_node[HD] = front_node->data;
        // }

        // ye hi done steps (front_node->left) aur (front_node->right) hamne upar wale function me bhi kiye hain
        if (front_node->left)
        {
            q1.push({front_node->left, HD - 1});
        }
        if (front_node->right)
        {
            q1.push({front_node->right, HD + 1});
        }
    }

    map<int, int>::iterator ite1; // contains HD and top_node ka data

    for (ite1 = top_node.begin(); ite1 != top_node.end(); ite1++)
    {
        ansur.push_back((*ite1).second);
    }

    return ansur;
}

vector<int> /*sixth function*/ left_view(Node * root)
{
    vector<int> ansur;

    iss_funct_ko_kya_naam_do(root,0,ansur);

    return ansur;
}

void /*sixth_1_function*/ iss_funct_ko_kya_naam_do (Node * root,int level,vector<int> &ansur)
{
    if(root==NULL)
    {
        return;
    }
    if(level==ansur.size())
    {
        ansur.push_back(root->data);
    }

    iss_funct_ko_kya_naam_do(root->left,level+1,ansur);
    iss_funct_ko_kya_naam_do(root->right,level+1,ansur);
}

int main()
{
    Node *root = build_tree(root);

    return 0;
}
