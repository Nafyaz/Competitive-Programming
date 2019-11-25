
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};
node *head;

void Insert(int data,int pos)
{
    int i=1;
    node *temp=head;
    while(i<pos)
    {
        if(temp->next==NULL)
        {
            printf("not valid position");
            exit(1);
        }
        temp=temp->next;
        i++;
    }
    node *temp2=(node*)malloc(sizeof(node));

    temp2->next=temp->next;
    temp2->data=data;
    temp->next=temp2;
}

void print()
{
    node *temp=head->next;
    while(1)
    {
        printf("%d ",temp->data);
        if(temp->next==NULL)
            break;
        temp=temp->next;
    }
}
