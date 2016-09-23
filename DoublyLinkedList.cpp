#include<iostream>
using namespace std;

struct node{
int data;
node* next;
node* prev;
};

node* getnode(int x){
    node* p = new node;
    p->data = x;
    p->next=p->prev=NULL;
}

void insertNode(node** head,int data,int pos)
{
    node* p = getnode(data);

    if(pos==1 || (*head)==NULL)
    {
        if(*head!=NULL)
            (*head)->prev = p;

        p->next = *head;
        *head = p;
        return;
    }

    node* temp = *head;
    for(int i=1;i<pos-1;i++) //Reach to the prev node
        temp=temp->next;

    p->next = temp->next;

    if(p->next!=NULL)
        p->next->prev = p;
    temp->next = p;
    p->prev = temp;
}

void traverse(node* head)
{
    if(head==NULL)
    {
        cout<<"Empty Linked List!\n";
        return;
    }

    node* i = head;

    while(i!=NULL)
    {
        cout<<i->data<<"-->";
        i=i->next;
    }

    cout<<"NULL\n";
}


int deleteNode(node** head,int pos)
{
    if(*head == NULL)
    {
        cout<<"Empty List!\n";
        return 0;
    }

    node* temp = *head;
    for(int i=1;i<pos;i++) //Reach to the node
        temp=temp->next;

    int data = temp->data;

    if(pos==1)
    {
        *head = temp->next;
        delete temp;
        return data;
    }

    temp->prev->next = temp->next;
    if(temp->next!=NULL)
        temp->next->prev = temp->prev;

    delete temp;
    return data;
}
int main()
{
node* head = NULL;
insertNode(&head,1,1);
insertNode(&head,2,2);
insertNode(&head,3,2);

deleteNode(&head,1);
deleteNode(&head,2);

traverse(head);
return 0;
}
