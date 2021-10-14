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

Node *Lsearch(Node *p, int key){
    while(p!=NULL){
        if(key==p->data){
            return p;//return the address of the node
        }
        p=p->next;
    }
    return NULL;
}



//faster Linear search using Move To Head
//move to front linear search: O(1) when searched for the 2nd time
Node *MTFsearch(Node *p, int key){
    Node *q=NULL;//tail pointer following p
    while(p!=NULL){
        if(key==p->data){
            q->next=p->next;
            p->next=first;//making p the first node
            first=p;//make the headPtr(first) p
            return p;//return the address of the node
        }
        q=p;
        p=p->next;
    }
    return NULL;

}


int main(){
    int A[]={5,15,25,35,45};
    create(A,5);
    Node *temp;
    temp=MTFsearch(first,15);
        if(temp){//not null then
            cout<<"Key is found: "<<temp->data;
        }
        else{
            cout<<"key not found";
        }
    return 0;
}