#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
}*first=NULL;//head pointer
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

void Display(Node *first){
    while(first !=NULL){
        cout<<first->data << " ";
        first=first->next;
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

int maxNode(Node *first){
    int max=-32768;//min 2 bit integer
    while(first!=NULL){
        if(first->data>max){
            max=first->data;
        }
        first=first->next;
    }
    return max;
}

Node *Lsearch(Node *first, int key){
    while(first!=NULL){
        if(key==first->data){
            return first;//return the address of the node
        }
        first=first->next;
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

int Delete(Node *p, int index){
    Node *q;
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

bool isSorted(Node *first){
    int x=-32768;
    Node *p=first;
    while(p!=NULL){
        if(p->data<x){
            return false;
        }
        x=p->data;
        p=p->next;
    }
    return true;
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

int AddNodes(Node *first){
    int sum=0;
    while(first!=NULL){
        sum+=first->data;
        first=first->next;
    }
    return sum;
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

int main(){
    int A[]={3,3,5,7,7,7};
    // Node *temp;

    create(A,6);
    // RDisplay(first);
    // cout<<RcountNode(first)<<endl;
    // cout<<AddNodes(first)<<endl;
    // cout<<maxNode(first)<<endl;
    // temp=Lsearch(first,7);
    //     if(temp){
    //         cout<<"Key is found: "<<temp->data;
    //     }
    //     else{
    //         cout<<"key not found";
    //     }
    
    // max(A,5);

    // temp=MTFsearch(first,10);
    //     if(temp){//not null then
    //         cout<<"Key is found: "<<temp->data;
    //     }
    //     else{
    //         cout<<"key not found";
    //     }
    // cout<<endl;
    // Insert(first,0,10);
    // Insert(first,1,10);
    // insertLast(10);
    // sortedInsert(first, 4);
    Display(first);
    // Delete(first,3);
    removeDuplicate(first);
    cout<<endl;
    Display(first);
    // cout<<isSorted(first);



    return 0;
}