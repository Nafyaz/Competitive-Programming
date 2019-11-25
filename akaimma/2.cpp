#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node *head=NULL;
void Append(int data)
{
    Node *new_Node=new Node;

    new_Node->data=data;
    new_Node->next=NULL;

    if(head==NULL)
    {
        head=new_Node;
        return;
    }

    Node *Temp=head;
    while(Temp->next!=NULL)
        Temp=Temp->next;

    Temp->next=new_Node;
}
Node* Insert(Node* head,int data)
{
    Node* Temp = head;
    Node* Temp2;
    if(head == NULL)
    {
    Temp2 = new Node;
    Temp2 -> data = data;
    Temp2 -> next = NULL;
    head = Temp2;
    //Temp -> next = Temp2;
    return head;
    }
    while(Temp->next != NULL) {

        Temp=Temp->next;
    }
    Temp2 = new Node;
    Temp2 -> data = data;
    Temp2 -> next = NULL;
    //head = Temp2;
    Temp -> next = Temp2;
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
int main()
{
    Append(3);
    Append(5);
    Append(1);
    Append(17);

    head=Insert(head,50);
    Print(head);

}
