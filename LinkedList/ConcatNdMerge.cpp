#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
}*first=NULL,*second=NULL,*third=NULL;//head pointer
//it becomes a global pointer

void create(int A[], int n){
    int i;
    Node *t, *last;
    first = new Node();
    first->data=A[0];//head ptr
    first->next=NULL;
    last=first;

    for(i=1;i<n;i++){
        t=new Node();
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void create2(int A[], int n){
    int i;
    Node *t, *last;
    second = new Node();
    second->data=A[0];//head ptr
    second->next=NULL;
    last=second;

    for(i=1;i<n;i++){
        t=new Node();
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void Display(Node *p){
    while(p !=NULL){
        cout<<p->data << " ";
        p=p->next;
    }
}


void Concat(Node *p, Node *q){
    third=p;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=q;
}


void Merge(Node *p,Node *q){
    Node *last;
    if(p->data < q->data){
        third=last=p;
        p=p->next;
        third->next=NULL;
    }
    else{
        third=last=q;
        q=q->next;
        third->next=NULL;
    }
    while(p && q){
        if(p->data < q->data){
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;

        }
        else{
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }
    if(p)
        last->next=p;
    if(q)
        last->next=q;
}

int main(){
    int A[]={5,15,25,35,45};
    int B[]={10,20,30,40,50};
    create2(B,5);
    create(A,5);

    Concat(first,second);
    // Merge(first,second);
    Display(third);
    return 0;
}