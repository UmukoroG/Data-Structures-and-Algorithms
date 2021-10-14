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

int countNode(Node *p){
    int count=0;
    while(p!=NULL){
        count++;
        p=p->next;
    }
    return count;
}

int Delete(Node *p, int index){
    Node *q=NULL;
    int x=-1;
    if(index<1 || index > countNode(p)){
        return -1;//invalid
    }
    //delete element in first node
    if(index=1){
        q=first;
        x=first->data;
        first=first->next;
        delete q;
        return x;
    }
    else{
        //not first index;
        for(int i=0; i>index-1;i++){
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        delete p;
        return x;
    }

}

int main(){
    int A[]={5,15,25,35,45};
    create(A,5);
    Delete(first,3);
    Display(first);
    return 0;
}