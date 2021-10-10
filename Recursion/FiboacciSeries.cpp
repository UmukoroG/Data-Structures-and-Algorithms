#include <iostream>
using namespace std;


int F[10];
int fib(int);
int mfib(int);

int main(){
    for(int i=0; i<10;i++){
        F[i]=-1;
    }

    cout<<mfib(5);
    return 0;
}

//excessive recursion: calling itself multiple times for the
// same functions already called
int fib(int n){//excessive recursion | time: O(2^n)
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    return fib(n-2)+fib(n-1); //n>1
}

// Memoization:Storing the result of the function call so they can 
// be re used again.

//Using Memoization store the recursion functions already 
// called in an array
int mfib(int n){
    if(n<=1){
        F[n]=n;
        return n;
   }
   else{
       if(F[n-2]==-1){
           F[n-2]=fib(n-2);
       }
       if(F[n-1]==-1){
           F[n-1]=fib(n-1);
       }
       F[n]= F[n-2] + F[n-1]
       return F[n-2]+F[n-1];
   }
}