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

void reverse(node* &head)
{
    node *prev=NULL;
    node *curr=head;
    node *next;

    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
}

node* reverse_kth(node* &head,int k)
{
    node *prev=NULL;
    node *curr=head;
    node *next;
    int count=0;

    while(curr!=NULL && count<k)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }
    if(next!=NULL)
    head->next=reverse_kth(next,k);

    return prev;
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

    cout<<"Reverse of a Linked list: \n";
  //  reverse(head1);
    display(head1);

    cout<<"\nReverse of a Kth node of a linked list: \n";
    head1=reverse_kth(head1,3);
    display(head1);
}