#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
}*first=NULL;

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

void Display(Node *p){
    while(p !=NULL){
        cout<<p->data << " ";
        p=p->next;
    }
}

void sortedInsert(Node *p, int x){
    Node *t, *q=NULL;
    t=new Node();
    t->data=x;
    t->next=NULL;

    //is it a first node? 
    if(first==NULL){
        first=t;
    }
    else{
        while(p && p->data<x){
            q=p;
            p=p->next;
        }
        if(p==first){
            //insert before first node
            t->next=first;
            first=t;
        }
        else{
            //insert before t and q pointer
            t->next=q->next;
            q->next=t;
        }
    }
}

bool isSorted(Node *p){
    int x=-32768;
    Node *q=p;
    while(q!=NULL){
        if(q->data<x){
            return false;
        }
        x=q->data;
        q=q->next;
    }
    return true;
}

int main(){
    int A[]={5,15,25,35,45};
    create(A,5);
    sortedInsert(first, 4);
    cout<<isSorted(first);
    return 0;
}