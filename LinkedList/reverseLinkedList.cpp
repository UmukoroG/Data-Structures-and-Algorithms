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


void Display(Node *p){
    while(p !=NULL){
        cout<<p->data << " ";
        p=p->next;
    }
}


// reverseLL using array to reverse data
// void reversingElement(Node *p){
//     Node *A;
//     int size=countNode(p);
//     A= new int[size];
//     Node *q=p;//for traversing

//     int i=0;
//     while(q!=NULL){
//         A[i]=q->data;
//         q=q->next;
//         i++;
//     }
//     q=p;
//     i--;
//     while(q!=NULL){
//         q->data=A[i];
//         q=q->next;
//         i--;
//     }
// }

// reversing LL using sliding pointers
void reverseLL(Node *p){
    p=first;
    Node *q=NULL;
    Node *r=NULL;
    while(p!=NULL){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}

int main(){
    int A[]={5,15,25,35,45};
    create(A,5);

    reverseLL(first);
    Display(first);
    return 0;
}