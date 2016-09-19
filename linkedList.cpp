#include<iostream>
using namespace std;

struct node{
    node* next;
    int data;
};

node* getNode(int x)
{
    node* p = new node;
    p->next = NULL;
    p->data = x;
}

void traverse(node* head){
    if(head == NULL)
    {
        cout<<"Empty List\n";
        return;
    }

    node* it = head;
    while(it != NULL){
        cout<<it->data<<"-->";
        it=it->next;
    }
}

/*void insertNode(node** head,int x){
    node* p = getNode(x);

    if(*head==NULL){
        cout<<"Empty List!\n";
        *head=p;
        return;
    }

    p->next = *head;
    *head = p;
}*/

/*node* insertNode(node* head,int x){
    node* p = getNode(x);

    if(head==NULL){
        //cout<<"Empty List!\n";
        head=p;
        return head;
    }

    p->next = head;
    head = p;
    return head;
}*/

node* insertNode(node* head,int x,int pos){
    node* p = getNode(x);

    if(head==NULL){
        head=p;
        //return head;
    }

    else if(pos==1)
    {
        p->next = head;
        head = p;
        //return head;
    }

    else
    {
        node* temp = head;
        for(int i=1;i<pos-1;i++)
            temp=temp -> next;

        p->next = temp->next;
        temp->next = p;
    }
return head;
}

node* deleteNode(node* head,int pos){

    if(head == NULL)
    {
        cout<<"Underflow Condition!\n";
        return NULL;
    }

    node* q = head;

    for(int i=1;i<pos-1;i++)
        q=q->next;

    if(pos==1)
    {
        node* temp = head;
        head=head->next;
        delete temp;
        return head;
    }

    node* temp = q->next;
    q->next = temp->next;
    delete temp;

    return head;
}

int main()
{
node* head = NULL;
head=insertNode(head,5,1);
head=insertNode(head,10,2);

head = deleteNode(head,1);
head = deleteNode(head,1);


traverse(head);
return 0;
}
