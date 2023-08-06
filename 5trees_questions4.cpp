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
        int count = 1;
        for (int j = i + 1; j < ansur.size(); j++)
        {

            if (ansur[i] == ansur[j])
            {
                count++;
                if (count == 2)
                {
                    inn_index_ko_delete_kardo.push_back(j);
                }
            }
        }
    }

    // cout << endl;
    // for (int i = 0; i < inn_index_ko_delete_kardo.size(); i++)
    // {
    //     cout << inn_index_ko_delete_kardo[i] << " ";
    // }
    // cout << endl;

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

/*













*/

Node *kth_ancestor_solver(Node *root, int &k, int node_ka_data)
{

    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == node_ka_data)
    {
        return root;
    }

    Node *left_ans = kth_ancestor_solver(root->left, k, node_ka_data);
    Node *right_ans = kth_ancestor_solver(root->right, k, node_ka_data);

    // ab wo wala logic likhenge ki agar ek non null return hua
    //  ya dono null hue to kya karein

    if (left_ans != NULL && right_ans == NULL)
    {
        k--;
        if (k <= 0)
        {
            // 'k' ko set kiya hai equal to maximum value so that it can never reach 0 again
            // it is done to ensure that kitna bhi upar chali jaaye recursion ki call, phir bhi k ki value kabhi 0 nahi hogi aur kabhi exact answer ke siwa kuch node return nahi hoga
            k = INT_MAX;
            return root;
        }
        return left_ans;
    }
    if (left_ans == NULL && right_ans != NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return right_ans;
    }
    if (left_ans == NULL && right_ans == NULL)
    {
        return NULL;
    }
}

int kth_ancestor(Node *root, int k, int node)
{
    Node *answer_hai = kth_ancestor_solver(root, k, node);
    if (answer_hai == NULL || answer_hai->data == node)
    {
        return -1;
    }
    else
    {
        return answer_hai->data;
    }
}

/*










*/

pair<int, int> solve_get_max_sum(Node *root)
{
    if (root == NULL)
    {
        return {0, 0};
    }

    pair<int,int> left=solve_get_max_sum(root->left);
    pair<int,int> right=solve_get_max_sum(root->right);
    pair<int,int> result={ (root->data+left.second+right.second) , ( max(left.first,left.second)+max(right.first,right.second) ) };
    return result;
}

int getMaxSum(Node *root)
{
    pair<int, int> ans = solve_get_max_sum(root);
    return max(ans.first, ans.second);
}

int main()
{
    Node *root = build_tree(root);
    cout << "Now saare path nikaalna" << endl;
    vector<vector<int>> ansur = saare_path_nikaal_dunga_tere(root);
    for (int i = 0; i < ansur.size(); i++)
    {
        for (int j = 0; j < ansur[i].size(); j++)
        {
            cout << ansur[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Now edited ansur" << endl;
    vector<vector<int>> ansur2 = funct2(ansur);
    for (int i = 0; i < ansur2.size(); i++)
    {
        for (int j = 0; j < ansur2[i].size(); j++)
        {
            cout << ansur2[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}