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


int maxNode(Node *p){
    int max=-32768;//min 2 bit integer
    while(p!=NULL){
        if(p->data>max){
            max=p->data;
        }
        p=p->next;
    }
    return max;
}

//recursive counting of linked list node
int RcountNode(Node *first){
    if(first==NULL){
        return 0;
    }
    else{
        return countNode(first->next)+1;
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


int main(){
    int A[]={5,15,25,35,45};
    create(A,5);

    cout<<countNode(first)<<endl;
    cout<<maxNode(first);
    return 0;
}