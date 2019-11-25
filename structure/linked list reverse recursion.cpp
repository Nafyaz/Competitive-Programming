#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *head=NULL;
void insert(int x)
{
    node *temp2;
    if(head==NULL)
    {
        temp2=(node *)malloc(sizeof(node));
        temp2->data=x;
        temp2->next=NULL;
        head=temp2;
        return;
    }

    node *temp1=head;

    while(temp1->next!=NULL)
    {
        temp1=temp1->next;
    }
    temp2=(node *)malloc(sizeof(node));
    temp2->data=x;
    temp2->next=NULL;
    temp1->next=temp2;
}

void reverse(node *p)
{
    if(p->next==NULL)
    {
        head=p;
        return;
    }
    reverse(p->next);
    node *q=p->next;
    q->next=p;
    p->next=NULL;
}

void print(node *temp)
{
    if(temp==NULL)
        return;
    printf("%d\n",temp->data);
    print(temp->next);
}

int main()
{
    insert(6);
    insert(-24);
    insert(-14);
    insert(192);
    insert(55);
    reverse(head);
    print(head);
}
