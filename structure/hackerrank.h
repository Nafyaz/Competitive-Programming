struct Node
{
    int data;
    Node *next;
};
//problem 3
Node* Prepend(Node* head, int data)
{
    Node *new_Node= new Node;
    new_Node->data=data;
    new_Node->next=head;

    return new_Node;
}
//problem 4
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
//problem 2
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
//problem 5
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
//problem 7
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
//problem 1
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
//problem 6
void ReversePrint(Node *head)
{
    if(head==NULL)
        return;
    ReversePrint(head->next);
    printf("%d\n",head->data);
}
//problem 8
int CompareLists(Node* headA, Node* headB)
{
    if(headA==NULL&&headB==NULL)
        return 1;
    if(headA==NULL||headB==NULL)
        return 0;
    while(1)
    {
        if(headA->data!=headB->data)
            return 0;
        if(headA->next==NULL&&headB->next==NULL)
            return 1;
        if(headA->next==NULL||headB->next==NULL)
            return 0;

        headA=headA->next;
        headB=headB->next;
    }
}
//problem 9
Node* MergeLists(Node* headA, Node* headB)
{
    if(headA==NULL)
        return headB;
    else if(headB==NULL)
        return headA;
    Node *head,*temp;
    if(headA->data<headB->data)
    {
        head=headA;
        headA=headA->next;
    }
    else
    {
        head=headB;
        headB=headB->next;
    }
    temp=head;
    while(1)
    {
        if(headA==NULL)
        {
            temp->next=headB;
            return head;
        }
        else if(headB==NULL)
        {
            temp->next=headA;
            return head;
        }
        if(headA->data<headB->data)
        {
            temp->next=headA;
            temp=temp->next;
            headA=headA->next;
        }
        else
        {
            temp->next=headB;
            temp=temp->next;
            headB=headB->next;
        }
    }
}
