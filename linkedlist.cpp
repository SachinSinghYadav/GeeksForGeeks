#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
};
class ll
{
    Node *head=NULL;
    public:
        void addatEnd(int);
        void traverse();
        void addatStart(int);
        void addatPosition(int,int);
        void deleteatPosition(int);
        void reversell();

};


void ll::addatEnd(int k)
{
   Node* newNode=new Node();
   newNode->data=k;
   newNode->next=NULL;
    if(head==NULL)
        head=newNode;
    else
    {
        Node *temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newNode;
    }
}
 void ll::traverse()
 {
    Node* t;
    t=head;
    while(t!=NULL)
    {
        cout<<t->data<<" ";
        t=t->next;
    }
 }
void ll::addatStart(int k)
{
    Node* newNode=new Node();
    newNode->data=k;
    newNode->next=head;
    head=newNode;
}
void ll::addatPosition(int n,int k)
{
    Node* newNode=new Node();
    newNode->data=k;
    newNode->next=NULL;
    if(n==1)
    {
        newNode->next=head;
        head=newNode;
    }
    else
    {
        Node* tmp1=head;
        for(int i=1;i<n-1;i++)
            tmp1=tmp1->next;
         newNode->next=tmp1->next;
         tmp1->next=newNode;
    }
}
void ll::deleteatPosition(int n)
{
    Node *temp=head;
    if(n==1)
    {
        head=temp->next;
        delete temp;
    }
    else
    {
        for(int i=1;i<n-1;i++)
            temp=temp->next;
        Node* temp2=temp->next;
        temp->next=temp2->next;
        delete(temp2);
    }
}
void ll::reversell()
{
    Node *current=head,*nxt,*prev=NULL;
    while(current!=NULL)
    {
        nxt=current->next;
        current->next=prev;
        prev=current;
        current=nxt;
    }
    head=prev;
}

int main()
{
    ll l;
    l.addatStart(4);
    l.addatEnd(5);
    l.addatEnd(6);
    l.traverse();
    cout<<endl;
    l.addatPosition(2,10);
    l.addatPosition(1,12);
    l.traverse();
    l.deleteatPosition(2);
     cout<<endl;
    l.traverse();
    l.reversell();
    cout<<endl;
    l.traverse();
}
