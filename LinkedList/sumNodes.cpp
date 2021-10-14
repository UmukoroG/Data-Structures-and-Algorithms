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


int AddNodes(Node *first){
    int sum=0;
    while(first!=NULL){
        sum+=first->data;
        first=first->next;
    }
    return sum;
}


int main(){
    int A[]={5,15,25,35,45};
    create(A,5);
    cout<<AddNodes(first);
    return 0;
}