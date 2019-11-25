#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};
node *head=NULL;

void Insert(int data)
{
    node *temp=head;

    if(head==NULL)
    {
        head=(node*)malloc(sizeof(node));
        head->data=data;
        head->next=NULL;
        return;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    node *temp2=(node *)malloc(sizeof(node));
    temp->next=temp2;
    temp2->data=data;
    temp2->next=NULL;
}

void Reverse()
{
    node *temp=head,*prev=NULL,*temp2;
    while(temp!=NULL)
    {
        temp2=temp->next;
        temp->next=prev;
        prev=temp;
        temp=temp2;
    }
    head=prev;
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

int main()
{
    Insert(2);
    Insert(5);
    Insert(-14);
    Insert(42);
    print();
    Reverse();
    print();
}
