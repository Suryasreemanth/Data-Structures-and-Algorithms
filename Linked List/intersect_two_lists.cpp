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

int length(Node *head)
{
    int l=0;
    while(head!=NULL)
    {
        head=head->next;
        l++;
    }
    return l;
}

int getIntersectionNode(Node *head1,Node *head2)
{
    int m=length(head1);
    int n=length(head2);

    Node *ptr1,*ptr2;
    int d;
    
    if(m>n)
    {
        d=m-n;
        ptr1=head1;
        ptr2=head2;
    }
    else{
        d=n-m;
        ptr1=head2;
        ptr1=head1;
    }

    while(d>0)
    {
        ptr1=ptr1->next;
        d--;
    }

    while(ptr1!=NULL)
    {
        if(ptr1==ptr2)
            return ptr1->data;

        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }

    return -1;

}

int main()
{
    /*
        Create two linked lists
     
        1st 3->6->9->15->30
        2nd 10->15->30
     
        15 is the intersection point
    */
 
    Node* newNode;
 
    // Addition of new nodes
    Node* head1 = new Node(3);
    head1->next=new Node(6);
    head1->next->next=new Node(9);
    head1->next->next->next=new Node(15);
    head1->next->next->next->next=new Node(30);

    // Intersecting Node
    newNode=head1->next->next->next;

    Node* head2 = new Node(10);
    head2->next=newNode;
    newNode->next=new Node(30);
    
 
    cout << "The node of intersection is " << getIntersectionNode(head1, head2)<<endl;;
}