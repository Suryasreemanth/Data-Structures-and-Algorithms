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

int length(node* head)
{
    int l=0;
    while(head!=NULL)
    {
        head=head->next;
        l++;
    }

    return l;
}

void append_kth(node* &head,int k)
{
    node *temp=head;
    node *newHead,*newTail;
    int count=1;
    int l=length(head);

    while(temp->next!=NULL)
    {
        if(count==l-k)
        {
            newTail=temp;
        }

        if(count==l-k+1)
        {
            newHead=temp;
        }
        temp=temp->next;
        count++;
    }
    newTail->next=NULL;
    temp->next=head;

    head=newHead;

}

void display(node* head)
{
    
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
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

    display(head1);

    append_kth(head1,3);

    display(head1);

}