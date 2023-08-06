#include <iostream>
using namespace std;
class node
{
public:
    node *prev;
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};
void print_linked(node *head)
{
    while (head != NULL)
    {
        cout << head->data << endl;
        head = head->next;
    }
}
int find_length(node *head)
{
    int len = 0;
    while (head != NULL)
    {
        // cout<<head->data<<endl;
        len++;
        head = head->next;
    }
    return len;
}
void insert_at_head(node *&head, int data)
{

    node *newnode = new node(data);
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
}
void insert_at_tail(node *&tail, int data)
{
    node *newnode = new node(data);
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
}
void insert_at_position(node *&head, int data, int position,node * tail)
{
    int tatt=find_length(head);
    if (position == 1)
    {
        insert_at_head(head, data);
    }
    else if ((tatt+1) !=position)
    {
        node *newnode = new node(data);
        node *temp = head;
        for (int i = 1; i <= position - 2; i++)
        {
            temp = temp->next;
        }
        node *temp2 = temp->next;
        temp->next = newnode;
        newnode->prev = temp;
        newnode->next = temp2;
        temp2->prev = newnode;
    }
    else if ((tatt+1)== position)
    {
        node *newnode = new node(data);
        tail->next=newnode;
        newnode->prev=tail;
    }
}
int main()
{
    node *head;
    node *tail;
    node *newnode = new node(20);
    head = tail = newnode;

    insert_at_head(head, 69);
    insert_at_head(head, 70);
    print_linked(head);
    cout << "now we have printed all the insert_at_heads" << endl;
    insert_at_tail(tail, 30);
    insert_at_tail(tail, 40);
    print_linked(head);
    cout << "now we have added node at tail" << endl;
    insert_at_position(head, 50, 4,tail);
    insert_at_position(head, 12, 7,tail);
    print_linked(head);
    
    return 0;
}