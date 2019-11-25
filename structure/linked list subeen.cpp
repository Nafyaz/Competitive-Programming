#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};
node *head;

node *create_node(int item,node *next)
{
    node *new_node=(node *)malloc(sizeof(node));
    if(new_node==NULL)
    {
        printf("baal amar");
        exit(1);
    }
    new_node->data=item;
    new_node->next=next;
    return new_node;
}

node *prepend(node *head, int item)
{
    node *new_node=create_node(item, head);
    return new_node;
}

node *append(node *head, int item)
{
    node *new_node=create_node(item,NULL);

    if(head==NULL)
        return new_node;

    node *current_node=head;

    while(current_node->next!=NULL)
        current_node=current_node->next;

    current_node->next=next=new_node;
    return head
}

void print(node *head)
{
    node *current_node=head;
    while(current_node!=NULL)
    {
        printf("%d ",current_node->data);
        current_node=current_node->next;
    }
    printf("\n");
}

int main()
{
    node *n1,*n2;
    n1=create_node(10,NULL);
    head=n1;

    head=prepend(head,20);
    n2=head;

    return 0;
}
