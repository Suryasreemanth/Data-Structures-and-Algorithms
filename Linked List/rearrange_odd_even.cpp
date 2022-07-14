#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;

    node(int x)
    {
        data=x;
        next=NULL;
    }
};

void odd_even_pos(node* &head)
{
    node *odd=head;
    node *even=head->next;
    node *Evenstart=even;

    while(odd->next!=NULL and even->next!=NULL)
    {
        odd->next=even->next;
        odd=odd->next;

        even->next=odd->next;
        even=even->next;
    }

    odd->next=Evenstart;
}

void display(node* head)
{   
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}


int main()
{
    node* head1 = new node(1);
    head1->next = new node(2);
    head1->next->next = new node(3);
    head1->next->next->next = new node(4);
    head1->next->next->next->next = new node(5);
    head1->next->next->next->next->next = new node(6);
    head1->next->next->next->next->next->next = new node(7);
    head1->next->next->next->next->next->next->next = new node(8);
    head1->next->next->next->next->next->next->next->next = new node(9);
    head1->next->next->next->next->next->next->next->next->next = new node(10);

    cout<<"Travrsal of a Linked list: ";
    display(head1);

    cout<<"\n Traversal of linked list after re-arranging odd and even positions:";
    odd_even_pos(head1);
    display(head1);
}