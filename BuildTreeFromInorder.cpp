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

int search(int inorder[],int  start,int end,int curr)
{
    for(int i=start;i<=end;i++)
    {
        if(inorder[i]==curr)
        {
            return i;
        }
    }

    return -1;
}

tree* BuildTree(int inorder[], int preorder[],int start,int end)
{
    if(start>end)
     return  NULL;

    static int idx=0;

    int curr=preorder[idx];
    idx++;

    tree *root=new tree(curr);
    int pos=search(inorder,start,end,curr);

    root->left=BuildTree(inorder,preorder,start,pos-1);
    root->right=BuildTree(inorder,preorder,pos+1,end);

    if(start==end)
    {
        return root;
    }

   return root;
}

void Inorder(tree *root)
{
    if(root==NULL)
        return ;
    
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
        
}

int main()
{
    int inorder[]={40,20,70,50,80,10,30,60};
    int preorder[]={10,20,40,50,70,80,30,60};

    tree *binary_tree=BuildTree(inorder,preorder,0,7);

    cout<<"Inorder traversal of a tree: ";
    Inorder(binary_tree);
    cout<<endl;
    
}