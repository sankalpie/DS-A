#include<bits/stdc++.h>

using namespace std;

class Node
{
    public:
    int data;
    Node * left;
    Node * right;
    Node(int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

// two sum
void twoSumhelper /*1.1*/ (Node* root,vector<int> & v1)
{
    if(root==NULL)
    {
        return ;
    }
    twoSumhelper(root->left,v1);
    v1.push_back(root->data);
    twoSumhelper(root->right,v1);
}

bool twoSum /*1.0*/(Node * root,int target)
{
    vector<int> v1;
    twoSumhelper(root,v1);

    int i=0,j=v1.size()-1;
    while(i<j)
    {
        if(v1[i]+v1[j]==target)
        {
            return true;
        }
        else if(v1[i]+v1[j]>target)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return false;
}


// make a sorted linked list from a given BST

void flat_BST_helper(Node * root,vector<Node*>& v1)
{
    if(root==NULL)
    {
        return;
    }
    flat_BST_helper(root->left,v1);
    v1.push_back(root);
    flat_BST_helper(root->right,v1);
}

Node * flat_BST (Node * root)
{
    vector<Node *> v1;
    flat_BST_helper(root,v1);
    
    for(int i=0;i<v1.size()-1;i++)
    {
        v1[i]->left=NULL;
        v1[i]->right=v1[i+1];
    }
    v1[v1.size()-1]->left=NULL;
    v1[v1.size()-1]->right=NULL;

    return v1[0];
}

// make a BST from preorder

Node * helper(vector<int> & preorder,int min,int max,int i)
{
    if(i>=preorder.size())
    {
        return NULL;
    }

    if(preorder[i]<min || preorder[i] >max)
    {
        return NULL;
    }
    
    Node * root=new Node(preorder[i++]);
    root->left=helper(preorder,min,root->data,i);
    root->right=helper(preorder,root->data,max,i);

    return root;    
}

Node * pre_to_BST(vector<int> & preorder)
{
    int min=INT_MIN;
    int max=INT_MAX;
    int i=0;
    helper(preorder,min,max,i);
}


//normal BST to balanced BST
void balance_BST_helper(Node * root,vector<int>& v1)
{
    if(root==NULL)
    {
        return;
    }
    balance_BST_helper(root->left,v1);
    v1.push_back(root->data);
    balance_BST_helper(root->right,v1);
}

Node * balance_BST_helper_2(vector<int> v1,int start,int end)
{
    if(start>end)
    {
        return NULL;
    }

    int mid=(start+end)/2;
    Node * root=new Node (v1[mid]);
    root->left=balance_BST_helper_2(v1,start,mid-1);
    root->right=balance_BST_helper_2(v1,mid+1,end);

    return root;
}

Node* balancedBst(Node* root) {
    // Write your code here.
    vector<int> v1;

    balance_BST_helper(root,v1);


    Node * root2= balance_BST_helper_2 (v1,0,v1.size()-1);

    return root2;
}

int main()
{
    
    return 0;
}