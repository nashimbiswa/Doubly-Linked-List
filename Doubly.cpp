#include<bits/stdc++.h>
using namespace std;

struct CircularLinkedList
{
    int data;
    CircularLinkedList *prev;
    CircularLinkedList *next;
    CircularLinkedList(int x)
    {
        data=x;
        prev=nullptr;
        next=nullptr;
    }
};

void insertionCLL(CircularLinkedList *&head,CircularLinkedList *&tail)
{
    int choice;
    CircularLinkedList *temp=head;
    do{
        int val;
        cout<<"Enter the value in circular linked list:\n";
        cin>>val;
        CircularLinkedList *newnode= new CircularLinkedList(val);
        if(head==nullptr){
            temp=tail=head=newnode;
        }
        else{   
            tail=newnode;
            newnode->prev=temp;
            temp->next=newnode;
            temp=temp->next;
        }
        
        cout<<"Enter your choice 1 to continue 0 and any other number to discontinue:\n";
        cin>>choice;
    }while(choice==1);
    
}

void display(CircularLinkedList *head){
    CircularLinkedList *temp=head;
    while (temp!=0)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

void insertAtBegin(CircularLinkedList *&head,int data,CircularLinkedList *&tail){
    CircularLinkedList *newnode=new CircularLinkedList(data);
    if(!head){
        head=tail=newnode;
    }
    else{
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
}

void insertAtEnd(CircularLinkedList *&head,int data,CircularLinkedList *&tail){
    CircularLinkedList *newnode=new CircularLinkedList(data);
    if(!head){
        head=tail=newnode;
    }
    else{
        newnode->prev=tail;
        tail->next=newnode;
        tail=newnode;
    }
}

void reverseLinkedlist(CircularLinkedList *&head,CircularLinkedList *&tail)
{
    if(!head or head->next==0)
        return;
    tail=head;
    CircularLinkedList *curr=head,*prev;
    while(curr!=0)
    {
        prev=curr->prev;
        curr->prev=curr->next;
        curr->next=prev;
        curr=curr->prev;
    }
    head=prev->prev;
}

void deleteHead(CircularLinkedList *&head,CircularLinkedList *&tail){
    // handling single node
    if(head->next==0){
        CircularLinkedList *temp=head;    
        head=0;
        tail=0;
        delete(temp);
    }
    else{
        CircularLinkedList *temp=head;
        head->next->prev=0;
        head=head->next;
        delete(temp);
    }
}

void deleteLastNode(CircularLinkedList *&head,CircularLinkedList *&tail){
     if(head->next==0){
        CircularLinkedList *temp=head;    
        head=0;
        tail=0;
        delete(temp);
    }
    else{
        CircularLinkedList *temp=tail;
        tail->prev->next=0;
        tail=tail->prev;
        delete(temp);
    }
}
int main(int argc, char const *argv[])
{
    CircularLinkedList *head=0,*tail=0;
    insertionCLL(head,tail);
    cout<<"Linked list data are as follows:\n";
    display(head);
    int data;
    // cout<<"\nInsert the new data in the beginning:\n";
    // cin>>data;
    // insertAtBegin(head,data,tail);
    // cout<<"\nInsert the new data at the end:\n";
    // cin>>data;
    // insertAtEnd(head,data,tail);
    // reverseLinkedlist(head,tail);
    // deleteHead(head,tail);
    deleteLastNode(head,tail);
    cout<<"\nUpdated list are as follows:\n";
    display(head);
    return 0;
}



