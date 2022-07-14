#include <bits/stdc++.h>
using namespace std;

struct node
{
    node *prev;
    int data;
    node *next;

    node(int x)
    {
        data=x;
        prev=next=NULL;
    }
};

void insert_at_beg(node* &head,int key)
{
    node *newHead=new node(key);

    newHead->next=head;

    if(head!=NULL)
    {
        head->prev=newHead;
    }
    head=newHead;
}

void insert_at_end(node* &head,int val)
{
    if(head==NULL)
    {
        insert_at_beg(head,val);
        return ;
    }

    node *newTail=new node(val);
    node *temp=head;

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    temp->next=newTail;
    newTail->prev=temp;
}

void display(node* head)
{
    cout<<"Traversal of a Double linked list ";

    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

int main()
{
    node *head=NULL;

    insert_at_beg(head,3);
    insert_at_beg(head,6);
    insert_at_beg(head,8);
    display(head);

    insert_at_end(head,7);
    insert_at_end(head,-15);
    display(head);
}