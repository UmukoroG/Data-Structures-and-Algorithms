#include <iostream>
using namespace std;

void Insert(int A[], int n){
    //n: index of an element 
    int i=n, temp;
    temp=A[i];

    while(i>1 && temp>A[i/2]){
        A[i]=A[i/2];
        i=i/2;
    }
    A[i]=temp;
}

// we can only delete the root for heap
int Delete(int A[], int n){
    int i, j , x,temp,val;
    val=A[1];//the deleted value
    x=A[n];
    A[1]=A[n];
    A[n]=val;//copy the deleted element at the last place: Heap sort
    i=1;
    j=i*2;//left child of i

    while(j<n-1){
        //if rchild>lchild
        if(A[j+1]>A[j])
            j=j+1;
        if(A[i]<A[j]){
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
            i=j;
            j=2*j;
        }
        else{
            break;
        }
    }
    return val;
}

int main(){
    int H[]={0,10,20,30,25,5,40,35};
    // Max Heap:40,25,35,10,5,20,30

    int i;
    for(i=2; i<=7;i++){
        Insert(H,i);
    }

    for(int i=1;i<=7;i++){
        cout<<H[i]<<" ";
    }
    cout<<endl;
    // cout<<Delete(H,7);
    for(int i=7;i>1;i--){
        Delete(H,i);
    }
    cout<<endl;
    for(int i=1;i<=7;i++){
        cout<<H[i]<<" ";
    }
    return 0;
}