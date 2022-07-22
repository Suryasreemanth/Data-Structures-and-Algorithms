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

int Height(tree *root)
{
    if(root==NULL)
        return 0;

    int rheight=Height(root->right);
    int lheight=Height(root->left);

    return max(rheight,lheight)+1;
}

int Diameter(tree *root)
{
    if(root==NULL)
        return 0;

    int rheight=Height(root->right);
    int lheight=Height(root->left);

    int currDmt=rheight+lheight+1;

    int rDmt=Diameter(root->right);
    int lDmt=Diameter(root->left);

    return max(currDmt,max(rDmt,lDmt));
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

    cout<<"Height of a tree: "<<Height(root);
    cout<<"\nDiameter of a tree: "<<Diameter(root);

}