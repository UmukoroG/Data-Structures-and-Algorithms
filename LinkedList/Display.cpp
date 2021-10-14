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

//Recursive display of a linked list: Higher space complexity
// than it's iteration counter part
void RDisplay(Node *first){
    if(first!=NULL){
        cout<<first->data << " ";
        RDisplay(first->next);
    }
}

void Display(Node *p){
    while(p !=NULL){
        cout<<p->data << " ";
        p=p->next;
    }
}



int main(){
    int A[]={5,5,25,35,45};
    create(A,5);

    Display(first);
    return 0;
}