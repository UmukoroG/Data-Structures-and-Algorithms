#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
}*first=NULL;


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

void Insert(Node *p, int index, int x){
    Node *t=NULL;
    //check if the index is valid
   if(index < 0 || index > countNode(p)){
       return; //invalid
   }
   t=new Node();
   t->data=x;

   //Insert at the node before first node
   if(index==0){
       t->next=first;
       first=t;
   }
   //Insert at any other position in the list
   else{
       for(int i=0; i<index-1;i++){
           p=p->next;
       }
       t->next=p->next;
       p->next=t;
   }
}

void insertLast(int x){
    Node *t=new Node();
    Node *last=NULL;
    t->data=x;
    t->next=NULL;
    if(first==NULL){
        first=last=t;
    }
    else{
        last->next=t;
        last=t;
    }
}


int main(){
    Insert(first,0,10);
    Insert(first,1,11);
    // insertLast(10);

    Display(first);
    
    return 0;
}