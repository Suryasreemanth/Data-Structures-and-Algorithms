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

void insert_at_any_pos(Node* &head,int pos,int key)
{
   if(pos==1)
   {
    Node *temp=new Node(key);
    temp->next=head;
    head=temp;
    return ;
   }

   else
   {
     Node *start=head;
     Node *temp=new Node(key);

     for(int i=1;i<=pos-1;i++)
     {
        start=start->next;
     }

     Node *nextNode=start->next;

     start->next=temp;
     temp->next=nextNode;

    }
}

void insert_at_end(Node* &head,int val)
{
    Node *newNode=new Node(val);
    Node *temp=head;

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    temp->next=newNode;
}

void display(Node *head)
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
    display(head);
    int pos,key;

    cout<<"\n Enter position and value you want to insert in the List : ";
    cin>>pos>>key;

    insert_at_any_pos(head,pos,key);
    display(head);

    insert_at_end(head,15);
    display(head);
}