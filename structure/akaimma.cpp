#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *add(Node *root,int data)
{
    Node *temp=new Node;
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;

    if(root==NULL)
        return temp;

    if(data<=root->data)
    {
        root->left=add(root->left,data);
        return root;
    }
    else
    {
        root->right=add(root->right,data);
        return root;
    }
}



bool isl(Node *root,int data)
{
    if(root==NULL)
        return true;
    if(root->data>data)
        return false;
    if(isl(root->left,data)&&isl(root->right,data))
        return true;
    else
        return false;
}
bool isg(Node *root, int data)
{
    if(root==NULL)
        return true;
    if(root->data<data)
        return false;
    if(isg(root->left,data)&&isg(root->right,data))
        return true;
    else
        return false;
}
bool isBST(Node *root)
{
    if(root==NULL)
        return true;
    if(isl(root->left,root->data)&&isg(root->right,root->data)&&isBST(root->left)&&isBST(root->right))
        return true;
    else
        return false;
}
int main()
{
    Node *root=NULL;
    root=add(root,12);
    root=add(root,14);
    root=add(root,8);
    root=add(root,10);
    printf("%d",isBST(root));
}
