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

vector<vector<int>> funct2(vector<vector<int>> ansur);
vector<vector<int>> saare_path_nikaal_dunga_tere(Node *root);

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

void /*first_1 function*/ issfunctkokyanaamdoo(Node *root, int len, int &maxlen, int sum, int &maxsum)
{
    if (root == NULL)
    {
        if (len > maxlen)
        {
            maxlen = len;
            maxsum = sum;
        }
        else if (len == maxlen)
        {
            maxsum = max(sum, maxsum);
        }
        return;
    }

    // sum=sum+root->data;

    issfunctkokyanaamdoo(root->left, len + 1, maxlen, sum + root->data, maxsum);
    issfunctkokyanaamdoo(root->right, len + 1, maxlen, sum + root->data, maxsum);
}

int /*first function*/ sum_of_longest_path(Node *root)
{
    // data structures bana lo
    int len = 0;    // jo current length hogi
    int maxlen = 0; // le max length ab tak ki hai

    int sum = 0;          // the sum we hve obtained till now in the path
    int maxsum = INT_MIN; // the maximum sum among all the paths we have travelled till now

    issfunctkokyanaamdoo(root, len, maxlen, sum, maxsum);
    return maxsum;
}

Node * /*second function*/ lca(Node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }

    Node *leftAns = lca(root->left, n1, n2);
    Node *rightAns = lca(root->right, n1, n2);

    if (leftAns != NULL && rightAns != NULL)
    {
        return root;
    }
    if (leftAns != NULL && rightAns == NULL)
    {
        return leftAns;
    }
    if (leftAns == NULL && rightAns != NULL)
    {
        return rightAns;
    }
    if (leftAns == NULL && rightAns == NULL)
    {
        return NULL;
    }
}

static int i = 0;

int sumK_mera /*third function*/(Node * root,int k)
{
    vector<vector<int>> ansur=saare_path_nikaal_dunga_tere(root);
    vector<vector<int>> ansur2=funct2(ansur);
    int kitne_aadmi_the=0;
    for(int i=0;i<ansur2.size();i++)
    { 
        int sum=0;
        for(int j=0;j<ansur2[i].size();j++)
        {
            sum=sum+ansur2[i][j];
        }
        if (sum==k)
        {
            kitne_aadmi_the++;
        }
    }

    return kitne_aadmi_the;
}

vector<vector<int>> saare_path_nikaal_dunga_tere(Node *root)
{
    vector<vector<int>> ansur;
    vector<int> mini_vector;

    if (root == NULL)
    {
        ansur.push_back(mini_vector);
        return ansur;
    }

    mini_vector.push_back(root->data);
    if (root->left == NULL && root->right == NULL)
    {
        ansur.push_back(mini_vector);
    }
    else
    {
        vector<vector<int>> left_paths = saare_path_nikaal_dunga_tere(root->left);
        vector<vector<int>> right_paths = saare_path_nikaal_dunga_tere(root->right);

        for (vector<int> &path : left_paths)
        {
            path.insert(path.begin(), root->data);
            ansur.push_back(path);
        }

        for (vector<int> &path : right_paths)
        {
            path.insert(path.begin(), root->data);
            ansur.push_back(path);
        }
    }

    ansur.push_back(mini_vector);

    return ansur;
}

vector<vector<int>> funct2(vector<vector<int>> ansur)
{
    vector<int> inn_index_ko_delete_kardo;

    for (int i = 0; i < ansur.size(); i++)
    {
        vector<int> temp = ansur[i];
        int count = 1;
        for (int j = i + 1; j < ansur.size(); j++)
        {

            if (temp == ansur[j])
            {
                count++;
            }
            if (count == 2)
            {
                inn_index_ko_delete_kardo.push_back(j);
            }
        }
    }

    // now deleting all the duplicates
    sort(inn_index_ko_delete_kardo.rbegin(), inn_index_ko_delete_kardo.rend());
    for (int index : inn_index_ko_delete_kardo)
    {
        if (index >= 0 && index < ansur.size())
        {
            ansur.erase(ansur.begin() + index);
        }
    }

    return ansur;
}

void solve(Node * root,int k, int & count, vector<int> path)
{
    if(root==NULL)
    {
        return;
    }
    path.push_back(root->data);

    solve(root->left,k,count,path);
    solve(root->right,k,count,path);
    //check for Ksum
    int size=path.size();
    int sum=0;

    for (int i=size-1;i>=0;i--)
    {
        sum+=path[i];
        if(sum==k)
        {
            count++;
        }
    }
    path.pop_back();
}

int sumK(Node * root,int k)
{
    vector<int>path;
    int count=0;
    solve(root,k,count,path);
    return count;
}

int main()
{
    Node *root = build_tree(root);
    cout << "Now sum of longest path" << endl;
    cout << sum_of_longest_path(root) << endl;
    cout << "Now saare path" << endl;
    vector<vector<int>> ansur = saare_path_nikaal_dunga_tere(root);
    for (int i = 0; i < ansur.size(); i++)
    {
        for (int j = 0; j < ansur[i].size(); j++)
        {
            cout << ansur[i][j] << " ";
        }
        cout << endl;
    }

    cout<<"Now edited ansur"<<endl;
    vector<vector<int>> ansur2=funct2(ansur);
    for (int i = 0; i < ansur2.size(); i++)
    {
        for (int j = 0; j < ansur2[i].size(); j++)
        {
            cout << ansur2[i][j] << " ";
        }
        cout << endl;
    }

    cout<<"Now kitne aadmi the"<<endl;
    cout<<sumK(root,3)<<endl;
    return 0;
}
// 4 2 7 -1 -1 1 6 -1 -1 -1 5 2 -1 -1 3 -1 -1

// 1 3 2 -1 -1 1 1 -1 -1 -1 7 4 1 -1 -1 2 -1 -1 5 -1 6 -1 -1