#include <bits/stdc++.h>
using namespace std;

struct Tree
{
    Tree *left;
    int data;
    Tree *right;

    Tree(int x)
    {
        data=x;
        left=right=NULL;
    }
};

void preorder(Tree *root)
{
    if(root!=NULL)
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void Inorder(Tree *root)
{
    if(root!=NULL)
    {
        Inorder(root->left);
        cout<<root->data<<" ";
        Inorder(root->right);
    }
}

void postorder(Tree *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}

int main()
{
    Tree *root =new Tree(10);
    root->left=new Tree(20);
    root->right=new Tree(30);

    root->right->right=new Tree(60);

    root->left->left=new Tree(40);
    root->left->right=new Tree(50);
    root->left->right->left=new Tree(70);
    root->left->right->right=new Tree(80);

   cout<<"Preorder Traversal of a Tree: ";
   preorder(root);
   cout<<endl;

   cout<<"Inorder Traversal of a Tree: ";
   Inorder(root);
   cout<<endl;

   cout<<"Postorder Traversal of a Tree: ";
   postorder(root);
}