#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int data) // constructor
    {
        this->data = data;
        this->next = NULL;
    }
};

void insert_at_beginning(int data, node *&head)
{
    node *temp = new node(data);
    temp->next = head;
    head = temp;
}

void print_linked(node *head)
{
    while (head != NULL)
    {
        cout << head->data << endl;
        head = head->next;
    }
}

void insert_at_end(int data, node *&tail)
{
    node *newnode = new node(data);
    tail->next = newnode;
    tail = newnode;
}

void insert_at_pos(int position, int data, node *&head, node *&tail)
{
    if (position == 1)
    {
        insert_at_beginning(data, head);
        return;
    }

    node *newnode = new node(data); // create a seperate node

    for (int i = 0; i <= position - 3; i++) // traverse to the desired position
    {
        head = head->next;
    }

    if (head->next == NULL)
    {
        insert_at_end(data, tail);
        return;
    }

    node *temp; // make a temp pointer to the next node of the head node
    temp = head->next;

    // temp se just pehle node insert hoga
    head->next = newnode;
    newnode->next = temp;
}

void delete_first(node * &head);//prototype for delete first

void delete_pos(int pos, node *&head)
{
    if(pos==1)
    {
        delete_first(head);
    }
    node *temp1 = head;
    node *temp2 = head;
    for (int i = 1; i <= pos - 2; i++)
    {
        temp1 = temp1->next;
    }
    temp2=temp1->next;

    temp1->next=temp2->next;
    delete(temp2);
}

void delete_first(node * &head)
{
    node * temp=head;
    head=head->next;
    delete(temp);
}

int main()
{
    node *head;
    node *tail;
    node *newnode = new node(1);
    head = newnode;
    tail = newnode;
    insert_at_beginning(2, head);
    insert_at_beginning(3, head);
    print_linked(head);
    cout << endl
         << endl
         << head->data;

    cout << endl
         << endl;
    insert_at_end(10, tail);
    insert_at_end(20, tail);
    insert_at_end(30, tail);
    print_linked(head);

    cout << endl
         << head->data << endl
         << endl;

    // now what if someone says that at 3rd position we need to insert 22
    insert_at_pos(1, 22, head, tail);
    print_linked(head);

    // now we need to delete nodes
    delete_pos(1, head);
    cout<<endl<<endl;
    print_linked(head);
    return 0;
}