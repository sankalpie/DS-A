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

// merge 2 BST 1.0
// O(n+m) time
// O(n+m) space
void inorder(Node *root, vector<int> &v1)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, v1);
    v1.push_back(root->data);
    inorder(root->right, v1);
}

vector<int> merge_helper(vector<int> &v1, vector<int> &v2)
{
    vector<int> v3;
    int i = 0, j = 0;
    while (i < v1.size() && j < v2.size())
    {
        if (v1[i] <= v2[j])
        {
            v3.push_back(v1[i]);
            i++;
        }
        if (v1[i] > v2[j])
        {
            v3.push_back(v2[j]);
            j++;
        }
    }

    while (i < v1.size())
    {
        v3.push_back(v1[i]);
        i++;
    }

    while (j < v2.size())
    {
        v3.push_back(v2[j]);
        j++;
    }

    return v3;
}

Node *inorder_se_BST(vector<int> &v3, int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    int mid = (start + end) / 2;
    Node *root = new Node(v3[mid]);
    root->left = inorder_se_BST(v3, start, mid - 1);
    root->right = inorder_se_BST(v3, mid + 1, end);
}

Node *merge_2_BST(Node *root1, Node *root2)
{
    vector<int> v1, v2;

    inorder(root1, v1);
    inorder(root2, v2);

    vector<int> v3 = merge_helper(v1, v2);

    Node *root_return = inorder_se_BST(v3, 0, v3.size() - 1);

    return root_return;
}

// merge BST 1.1
// O(n+m) time
// O(ht1+ht2) space
// the space complexity should be the sum of heights not the sum of number of nodes

    // so 1st step convert the trees both to a flatten sorted linked list
    // merge two sorted linked list so doing this we get time complexity O(m+n) and space O(1)
    // convert the sorted LL to a BST

// convert to LL

void convertTO_DoublyLL(Node *root, Node *&head)
{
    if (root == NULL)
    {
        return;
    }
    convertTO_DoublyLL(root->right, head);
    root->right = head;
    if (head != NULL) //agar right part hi na ho toh head bhi NULL ayega so agar head nULL na ho toh hi hum head->left=root karenge
    {
        head->left = root;
    }
    head=root;

    convertTO_DoublyLL(root->left,head);

}

Node * merge_2_doubly_LL(Node * head1, Node * head2)
{
    Node * head3=NULL;
    Node * tail3=NULL;

    while(head1!=NULL && head2 != NULL)
    {
        if(head1->data<head2->data)
        {
            if(head3==NULL)
            {
                head3=head1;
                tail3=head1;
                head1=head1->right;
            }
            else
            {
                //insert at end
                tail3->right=head1;
                head1->left=tail3;
                tail3=head1;
                head1=head1->right;
            }
        }
        else
        {
            if(head3==NULL)
            {
                head3=head2;
                tail3=head2;
                head2=head2->right;
            }
            else
            {
                //insert at end
                tail3->right=head2;
                head2->left=tail3;
                tail3=head2;
                head2=head2->right;
            }
        }
    }

    while(head1!=NULL)
    {
        //insert at end
        tail3->right=head1;
        head1->left=tail3;
        tail3=head1;
        head1=head1->right;
    }
    while(head2!=NULL)
    {
        //insert at end
        tail3->right=head2;
        head2->left=tail3;
        tail3=head2;
        head2=head2->right;
    }

    return head3;
}


int count_nodes(Node * head)
{
    int count=0;
    Node * temp=head;
    while(temp != NULL)
    {
        count++;
        temp=temp->right;
    }
    return count;
}

Node * convert_doubly_LL_toBST(Node * head,int n)
{
    if(n<=0 || head==NULL)
    {
        return NULL;
    }
    Node * left=convert_doubly_LL_toBST(head,n/2);

    Node * root=head;
    root->left=left;

    root->right=convert_doubly_LL_toBST(head, n- (n/2-1));

    return root;
}

int main()
{

    return 0;
}