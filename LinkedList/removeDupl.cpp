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


void removeDuplicate(Node *p){
    Node *q=p->next;

    while(q!=NULL){
        if(p->data!=q->data){
            p=q;
            q=q->next;
        }
        else{
            p->next=q->next;
            delete q;
            q=p->next;
        }
    }
}

int main(){
    int A[]={5,5,25,35,45};
    create(A,5);
    removeDuplicate(first);
    Display(first);
    return 0;
}