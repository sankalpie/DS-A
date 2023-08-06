#include<bits/stdc++.h>

using namespace std;

class Node
{
    public:
    int data;
    Node * next;

    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};



int main()
{
    Node * head;
    Node * node1= new Node(69);
    head = node1;

    // node1->data=69;
    // cout<<node1->data;
    // node1->next=NULL;
    // cout<<endl<<node1->next;

    Node *node2=new Node(70);
    head->next=node2;

    Node * temp=head;
    while(temp!= NULL)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }


    return 0;
}