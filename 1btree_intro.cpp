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

node * buildtree(node * root)
{
    cout<<"enter data "<<endl;
    int data;
    cin>>data;
    root = new node(data);
 
    if(data==-1)
    {
        return NULL;
    }

    cout<<"enter left node of "<<data<<endl;
    root->left=buildtree(root->left);
    cout<<"enter right node of "<<data<<endl;
    root->right=buildtree(root->right);
    return root;
}

void leveltraversal(node * root)
{
    queue<node *> q1;
    q1.push(root);
    
    while(!q1.empty())
    {
        node * temp=q1.front();
        cout<<temp->data<<" ";
        q1.pop();

        if(temp->left)
        {
            q1.push(temp->left);
        }
        if(temp->right)
        {
            q1.push(temp->right);
        }
    }
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
}

void leveltraversalimproved(node * root)
{
    //to get each level of b tree in seperate lines we need to use a seperator
    queue<node *>q1;
    q1.push(root);
    //q1 me root ko push karne ke baad we are sure that level 0 is completed so we now push a seperator
    q1.push(NULL);

    while(! q1.empty() )
    {
        node * temp=q1.front();
        q1.pop();

        if(temp==NULL)
        {
            cout<<endl;
            if(! q1.empty())
            {
                q1.push(NULL);
            }
        }
        else
        {
            cout<<temp->data<<" ";
            if(temp->left)
            {
                q1.push(temp->left);
            }
            if(temp->right)
            {
                q1.push(temp->right);
            }
        }
    }
}

void inorder(node * root)
{
    //LNR
    if(root==NULL)
    {
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(node * root)
{
    //LNR
    if(root==NULL)
    {
        return ;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node * root)
{
    //LNR
    if(root==NULL)
    {
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

//haan buildformlevel hi tha woh
void buildfromlevel(node * &root)
{
    queue<node *>q1;
    cout<<"Enter data "<<endl;
    int data;
    cin>>data;
    root=new node(data);

    q1.push(root);

    while(!q1.empty())
    {
        node * temp=q1.front();
        q1.pop();

        cout<<"Now enter left node for "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;
        if(leftdata!=-1)        
        {
            temp->left=new node(leftdata);
            q1.push(temp->left);
        }
        cout<<"Now enter right node for "<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;
        if(rightdata!=-1)
        {
            temp->right=new node(rightdata);
            q1.push(temp->right);
        }
    }
}

int leafCount=0;

void countLeaves(node * root)
{
    //ek kaam karte hai inorder traversal karte hai and then if the root->right ==NULL || root->left ==NULL then we will add 1 to leafCount
    //LNR
    if(root==NULL)
    {
        return;
    }
    if(root->left==NULL && root->right==NULL)
    {
        leafCount++;
    }
    countLeaves(root->left);
    countLeaves(root->right);
}


int main()
{
    node * root=NULL;

    /*
    buildfromlevel(root);
    cout<<endl;
    cout<<endl;
    leveltraversal(root);
    */

    
    root=buildtree(root);

    leveltraversal(root);
    cout<<endl;
    cout<<endl;
    leveltraversalimproved(root);
    cout<<endl;
    cout<<endl;
    cout<<"inorder traversal is "<<endl;
    inorder(root);
    cout<<"\npreorder traversal is "<<endl;
    preorder(root);
    cout<<"\npostorder traversal is "<<endl;
    postorder(root);
    cout<<endl;
    cout<<"------------------------------\n";
    cout<<endl;

    //now write a function to count the leaf nodes
    // 20 10 5 -1 -1 15 13 -1 -1 -1 35 30 -1 -1 42 -1 -1
    // int leafCount;
    countLeaves(root);
    cout<<leafCount<<endl;
    return 0;
} 