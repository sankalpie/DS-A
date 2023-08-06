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

Node *insert_into_bst /*1.1 function*/ (Node *&root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    if (data > root->data)
    {
        // insert in right part
        root->right = insert_into_bst(root->right, data);
    }
    else if (data <= root->data)
    {
        root->left = insert_into_bst(root->left, data);
    }
    return root;
}

void take_input /*1.0 function*/ (Node *&root)
{
    int inp;
    cin >> inp;

    while (inp != -1)
    {
        // Node * newnode=new Node(inp);
        root = insert_into_bst(root, inp);

        cin >> inp;
    }
}

void level_order(Node *root)
{
    queue<Node *> q1;
    q1.push(root);

    q1.push(NULL);

    while (!q1.empty())
    {
        Node *frontnode = q1.front();
        q1.pop();

        if (frontnode == NULL)
        {
            cout << endl;
            if (!q1.empty())
            {
                q1.push(NULL);
            }
        }
        else
        {
            cout << frontnode->data << " ";

            if (frontnode->left)
            {
                q1.push(frontnode->left);
            }
            if (frontnode->right)
            {
                q1.push(frontnode->right);
            }
        }
    }
}

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

bool search_in_bst_recursively /*2.0 function*/ (Node *root, int search_data)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data > search_data)
    {
        return search_in_bst_recursively(root->left, search_data);
    }
    if (root->data < search_data)
    {
        return search_in_bst_recursively(root->right, search_data);
    }

    if (root->data == search_data)
    {
        return true;
    }
}

bool search_in_bst_iteratively /*2.1 function*/ (Node *root, int search_data)
{
    Node *temp = root;

    while (temp != NULL)
    {
        if (temp->data == search_data)
        {
            return true;
        }

        if (temp->data > search_data)
        {
            temp = temp->left;
        }
        else if (temp->data < search_data)
        {
            temp = temp->right;
        }
    }
    return false;
}

Node *minvalue_recursively /*3.0 function*/ (Node *root)
{
    if (root->left == NULL)
    {
        return root;
    }
    return minvalue_recursively(root->left);
}

Node *minvalue_iteratively /*3.1 function*/ (Node *root)
{
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}










int inorderSuccessor (Node * root, int val)
{
    int ansur=-1;
    while(root!=NULL)
    {
        if(root->data <= val)
        {
            root=root->right;
        }
        else
        {
            ansur=root->data;
            root=root->left;
        }
    }

    return ansur;
}









Node * delete_from_bst(Node * root,int val)
{
    if(root==NULL)
    {
        return root;
    }
    if(root->data==val)
    {
        //actual DELETE_KA_CODE
        //0 child
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            return NULL;
        }
        //1 child
            //1 child is left child
            if(root->left !=NULL && root->right==NULL)
            {
                Node * temp=root->left;
                delete root;
                return temp;
            }
            //1 child is right child
            if(root->left==NULL && root->right != NULL)
            {
                Node * temp=root->right;
                delete root;
                return temp;
            }
        //2 child
        if(root->left != NULL && root->right != NULL)
        {
            Node * mini = minvalue_recursively(root->right);
            root->data= mini->data;
            root->right=delete_from_bst(root->right,mini->data);
            return root;
        } 


    }
    else if(root->data > val)
    {
        root->left=delete_from_bst(root->left,val);
        return root;
    }
    else
    {
        root->right=delete_from_bst(root->right,val);
        return root;
    }
}






int main()
{
    Node *root;
    root = NULL;
    cout << "Enter data's to create BST" << endl;
    take_input(root);

    cout << "Now printing level order" << endl;
    level_order(root);

    cout << "Now printing data in root" << endl;
    cout << root->data;

    cout << "\nNow printing inorder " << endl;
    inorder(root);

    cout << "\nNow printing minValue recursively" << endl;
    cout << minvalue_recursively(root)->data << endl;

    cout << "\nNow printing minValue iteratively" << endl;
    cout << minvalue_iteratively(root)->data << endl;

    

    return 0;
}
// 10 8 21 7 27 5 4 3 -1