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

void remove_loop(node* &slow,node *head)
{
  // base case if cycle starts with head of the node
    if(slow==head)
    {
        while(slow->next!=head)
            slow=slow->next;

        slow->next=NULL;
    }

    while(slow->next!=head->next)
    {
        slow=slow->next;
        head=head->next;
    }

    slow->next=NULL;
}

bool detect_cycle(node* &head)
{
    node *slow=head;
    node *fast=head;

    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast)
        {
            remove_loop(slow,head);
            return true;
        }
    }
    return false;
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

    head1->next->next->next->next->next->next->next->next->next=head1->next->next->next;

    cout<<detect_cycle(head1)<<endl;

    display(head1);

}