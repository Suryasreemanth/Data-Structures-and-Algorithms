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

int countNodes(tree *root)
{
    if(root==NULL)
        return 0;

    return countNodes(root->left)+countNodes(root->right)+1;
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

    cout<<" Total number of nodes: "<<countNodes(root);

}