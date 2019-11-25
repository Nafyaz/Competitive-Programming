#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
};

Node* Prepend(Node* head, int data)
{
    Node *new_Node= new Node;
    new_Node->data=data;
    new_Node->next=head;

    return new_Node;
}
Node* InsertNth(Node* head, int data, int position)
{
    Node *new_Node=new Node;
    new_Node->data=data;
    if(position==0)
    {
        new_Node->next=head;
        return new_Node;
    }

    Node *temp=head;int i=1;
    while(i<position)
    {
        i++;
        temp=temp->next;
    }
    new_Node->next=temp->next;
    temp->next=new_Node;

    return head;
}
Node* Append(Node* head, int data)
{
    Node *new_Node=new Node;

    new_Node->data=data;
    new_Node->next=NULL;

    if(head==NULL)
    {
        head=new_Node;
        return head;
    }

    Node *temp=head;
    while(temp->next!=NULL)
        temp=temp->next;

    temp->next=new_Node;
    return head;
}
Node* Delete(Node *head, int position)
{
    Node *temp2;
    if(position==0)
    {
        temp2=head;
        head=temp2->next;
        delete temp2;
        return head;
    }
    Node *temp=head;
    int i=1;
    while(i<position)
    {
        temp=temp->next;
        i++;
    }
    temp2=temp->next;
    temp->next=temp2->next;
    delete temp2;

    return head;
}
Node* Reverse(Node* head)
{
    Node *prev=NULL,*temp;
    while(head->next!=NULL)
    {
        temp=head->next;
        head->next=prev;
        prev=head;
	    head=temp;
    }
    head->next=prev;
    return head;
}
void Print(Node* head)
{
    Node *temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void ReversePrint(Node *head)
{
    if(head==NULL)
        return;
    ReversePrint(head->next);
    printf("%d\n",head->data);
}
int main()
{
    Node *head=NULL;

    head=Append(head,32);
    //Print(head);
    head=Append(head,13);
    //Print(head);
    head=Append(head,3);
    //Print(head);
    head=Append(head, 114);
    //Print(head);

    head=Reverse(head);
    Print(head);
}
