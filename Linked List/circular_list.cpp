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

void del_at_beg(node* &head)
{
    node *temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }

    node *delnode=head;
    temp->next=head->next;
    head=head->next;

    delete delnode;

}

void insert_at_beg(node* &head,int val)
{
    node *beg=new node(val);

    if(head==NULL)
    {
        head=beg;
        return;
    }

    node *temp=head;

    while(temp->next!=head)
    {
        temp=temp->next;
    }

    beg->next=head;
    temp->next=beg;

    head=beg;
}

void insert_at_end(node* &head,int val)
{
    node *last=new node(val);
    node *temp=head;

    while(temp->next!=head)
    {
        temp=temp->next;
    }

    temp->next=last;
    last->next=head;
}


void display(node* head)
{
    node *temp=head;
    
    cout<<" Traversal of circular linked list: ";

    do
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=head);

    cout<<endl;
}

int main()
{
    node* head1 = new node(1);
    head1->next = new node(2);
    head1->next->next = new node(3);
    head1->next->next->next = new node(4);
    head1->next->next->next->next = new node(5);
    head1->next->next->next->next->next=head1;

    insert_at_end(head1,20);
    insert_at_beg(head1,-7);

    display(head1);


    del_at_beg(head1);
    display(head1);
    
}