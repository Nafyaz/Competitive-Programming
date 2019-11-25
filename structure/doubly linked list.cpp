#include<bits/stdc++.h>
using namespace std;
struct node
{
    node *prev;
    int data;
    node *next;
};
node *head=NULL;
node *tail=NULL;
void insert(int x)
{
    node *temp=(node *)malloc(sizeof(node));

    temp->data=x;
    temp->next=NULL;

    if(head==NULL)
    {
        temp->prev=NULL;
        head=temp;
        tail=temp;
        return;
    }
    temp->prev=tail;
    tail->next=temp;
    tail=temp;
}
void print()
{
    node *temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void printRev()
{
    node *temp=tail;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->prev;
    }
    printf("\n");
}
int main()
{
    insert(34);
    insert(1);
    insert(-24);
    insert(2);
    insert(5);

    print();
    printRev();
}
