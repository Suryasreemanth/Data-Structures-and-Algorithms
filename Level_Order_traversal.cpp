#include <bits/stdc++.h>
using namespace std;

struct tree
{
    tree *left;
    int data;
    tree *right;

    tree(int x)
    {
        data=x;
        left=right=NULL;
    }
};

int sum=0;
void print_kth_level(tree *root, int k)
{
    
    if(root==NULL)
    return ;

    if(k==0)
    {
        cout<<root->data<<" ";
        sum=sum+root->data;
    }
    else{
            print_kth_level(root->left,k-1);
            print_kth_level(root->right,k-1); 
         }
      
}

void LevelOrder(tree *root)
{
    queue<tree *> q;
    q.push(root);

    while(q.empty()==false)
    {
        tree *curr=q.front();
        q.pop();
        cout<<curr->data<<" ";

        if(curr->left!=NULL)
            q.push(curr->left);

        if(curr->right!=NULL)
            q.push(curr->right);
        
    }
}

int main()
{
    int k;
    tree *root =new tree(10);
    root->left=new tree(20);
    root->right=new tree(30);

    root->right->right=new tree(60);

    root->left->left=new tree(40);
    root->left->right=new tree(50);
    root->left->right->left=new tree(70);
    root->left->right->right=new tree(80);

   cout<<"Level order Traversal of a Tree: ";
   LevelOrder(root);
   cout<<endl;

   cout<<" elements at kth level: ";
   print_kth_level(root,2);

   cout<<"\nsum of elements at kth level: "<<sum;
  
    
}