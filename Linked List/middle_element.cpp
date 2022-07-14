#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  Node *next;
  
  Node (int x)
  {
      data=x;
      next=NULL;
  }
};

void find_middle(Node *head)
{
     
    Node *slow_ptr,*fst_ptr;
    slow_ptr=fst_ptr=head;
    
    while(fst_ptr!=NULL and fst_ptr->next!=NULL)
    {
        slow_ptr=slow_ptr->next;
        fst_ptr=fst_ptr->next->next;
    }
    
    cout<<" \nMiddle element: "<<slow_ptr->data<<endl;
}

int main()
{
    Node *head,*temp,*start,*st2;
    int n,val;

    cout<<"Enter the number of nodes of data: ";
    cin>>n;
    
    cout<<"Enter "<<n<<" Values for linked list"<<endl;
        cin>>val;

    head=new Node(val);
    start=head;
    
    for(int i=2;i<=n;i++)
    {
        cin>>val;
        temp=new Node(val);
        start->next=temp;
        start=start->next;
    }
    st2=head;
    
    cout<<"Traversal of a linked list\n";
    while(st2!=NULL)
    {
        cout<<st2->data<<" ";
        st2=st2->next;
    }
    find_middle(head);
}
