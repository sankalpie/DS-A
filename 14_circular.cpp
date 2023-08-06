#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
    }
};

void insert(node *&tail, int element, int data)
{
    node *newnode = new node(data);
    // cout<<"I was here"<<endl;
    if (tail == NULL)
    {

        tail = newnode;
        newnode->next = newnode;
        // cout<<"I was here"<<endl;
    }
    else
    {
        node *tatt = tail;
        // cout<<tatt->next->next->next->data<<endl;
        while (tatt->data != element)
        {
            tatt = tatt->next;
        }
        node *newnode = new node(data);
        newnode->next = tatt->next;
        tatt->next = newnode;
    }
}

void print_linked(node *tail)
{
    node *temp = tail;
    do
    {
        cout << tail->data << endl;
        tail = tail->next;
        /* code */
    } while (/* condition */ tail != temp);
}

void deletenode(node *&tail, int element_to_delete)
{
    node *copy = tail;
    if (copy->data != element_to_delete)
    {
        node *before_copy = NULL;
        while (copy->data != element_to_delete)
        {
            before_copy = copy;
            copy = copy->next;
        }
        before_copy->next = copy->next;
        copy->next = NULL;
        delete copy;
    }
    else if (copy->data == element_to_delete)
    {
        node *before_copy = NULL;
        copy = copy->next;
        while (copy->data != element_to_delete)
        {
            before_copy = copy;
            copy = copy->next;
        }
        before_copy->next = copy->next;
        copy->next = NULL;
        tail=before_copy->next;
        delete copy;
    }
}

int main()
{
    node *tail = NULL;
    insert(tail, 0, 3);
    insert(tail, 3, 5);
    insert(tail, 5, 7);
    insert(tail, 7, 9);
    insert(tail, 5, 6);
    print_linked(tail);
    cout << "now we will delete nodes" << endl;
    deletenode(tail, 3);
    print_linked(tail);
    cout<<"see this"<<endl;
    insert(tail, 7, 10);
    print_linked(tail);
    return 0;
}