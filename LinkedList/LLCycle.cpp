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

int isLoop(Node *f){
    Node *q, *p;
    p=q=f;
    do{
        p=p->next;
        q=q->next;
        q=q?q->next:q;
    }while(p && q && p!=q);
    if(p==q){
        return 1;
    }
    else{
        return 0;
    }
}



int main(){

    Node *t1, *t2;

    int A[]={5,15,25,35,45};

    create(A,5);
    t1=first->next->next;
    t2=first->next->next->next->next;
    t2->next=t1;
    cout<<isLoop(first);
    
    return 0;
}