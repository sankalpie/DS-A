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
        this->next = NULL;
    }
};

void insert_at_tail(int data, node *&tail)
{
    node *newnode = new node(data);
    tail->next = newnode;
    tail = newnode;
}

void print_linked(node *head)
{
    while (head != NULL)
    {
        cout << head->data << endl;
        head = head->next;
    }
}

node *reverse_linked(node * &head);

int main()
{
    node *head;
    node *tail;
    node *newnode = new node(20);
    head = tail = newnode;

    insert_at_tail(30, tail);
    insert_at_tail(40, tail);
    insert_at_tail(50, tail);
    insert_at_tail(60, tail);
    insert_at_tail(70, tail);
    print_linked(head);

    // code to reverse linked list
    //I have shown 2 methods of reversing the LL, one is without the function and one is via function, dont worry
    node *prev = NULL;
    node *curr = head;

    while (curr != NULL)
    {
        node *forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        head = prev;
    }
    cout << "now lets try to reverse the list" << endl;
    print_linked(head);
    cout << "again reversing" << endl;
    print_linked(reverse_linked(head));
    return 0;
}

// void reverse(node * head, node * curr, node * prev)
// {

// }

// the reverse_linked function will give you the head pointer of the reversed linked list
node *reverse_linked(node * &head)
{
    // base case is that when head==NULL or head->next==NULL then we have to stop
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    node *chotahead = reverse_linked(head->next);

    head->next->next = head;
    head->next = NULL;

    return chotahead;
}