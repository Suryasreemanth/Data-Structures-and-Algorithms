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

void preorder(tree *root)
{
    if(root==NULL)
        return ; 

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}

void Inorder(tree *root)
{
    if(root==NULL)
        return ;
    
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
        
}

void postorder(tree *root)
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
    tree *root=new tree(10);
    root->left=new tree(20);
    root->right=new tree(30);

    root->left->left=new tree(40);
    root->left->right=new tree(50);
    root->left->right->left=new tree(70);
    root->left->right->right=new tree(90);

    root->right->right=new tree(60);

    cout<<"Preorder traversal of a tree: ";
    preorder(root);
    cout<<endl;

    cout<<"Inorder traversal of a tree: ";
    Inorder(root);
    cout<<endl;

    cout<<"Postorder traversal of a tree: ";
    postorder(root);
    cout<<endl;
}