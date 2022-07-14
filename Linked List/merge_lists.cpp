#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data=x;
        next=NULL;
    }
};

Node* merge_list(Node* &head1,Node* &head2)
{
    Node *head3=new Node(-1);
    Node *newList=head3;

    while(head1!=NULL && head2!=NULL)
    {
        if(head1->data > head2->data)   
        {
            head3->next=head2;
            head2=head2->next;
        }
        else
        {
            head3->next=head1;
            head1=head1->next;
        }
        head3=head3->next;
    }
     
    while(head1!=NULL)
    {
        head3->next=head1;
        head1=head1->next;
        head3=head3->next;
    }

      while(head2!=NULL)
    {
        head3->next=head1;
        head2=head2->next;
        head3=head3->next;
    }

    return newList->next;
}

void display(Node* head)
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
    /*
        Create two linked lists
     
        1st 3->6->9->15->21
        2nd 10->20->30
     
        combine two sorted lists to form a list
    */
 
    Node* newNode;
 
    // Addition of new nodes
    Node* head1 = new Node(3);
    head1->next=new Node(6);
    head1->next->next=new Node(9);
    head1->next->next->next=new Node(15);
    head1->next->next->next->next=new Node(30);
    cout<<"Traversal of 1st linked list: ";
    display(head1);
    // Intersecting Node
    
    Node* head2 = new Node(10);
    head2->next=new Node(20);
    head2->next->next=new Node(30);
    cout<<"Traversal of 2nd linked list: ";
    display(head2);


    Node* newHead=merge_list(head1,head2);
    cout<<"Traversal of merged linked list: ";
    display(newHead);
}