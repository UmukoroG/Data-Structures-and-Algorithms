#include <iostream>
using namespace std;

// Recursion:A Base case and it calls itself

// void fun(int n){//tail recursion 
//     if(n>0){
//         cout<<n; // 321
//         fun(n-1);
//     }
// } //O(n): time

// void fun(int n){//head recursion
//     if(n>0){
//         fun(n-1); //get to 0 before executing print from bottom up
//         cout<<n; // 123
        
//     }
// }//O(n) : time

void fun(int n){//Tree recursion:function calls itself more than once
    if(n>0){//Fibonacci series
        cout<<n; 
        fun(n-1); //finishes all recursion process => 123
        fun(n-1); //new Activation record is then created for the 2nd func call => 1211
        
    }
}//O(2^n) : time


//INDIRECT RECURSION: CALLING EACHOTHER LIKE A CYCLE
void funB(int);

void funA(int n){
    if(n>0){
        cout<<n;
        funB(n-1);
    }
}

void funB(int n){
    if(n>1){    
        cout<<n;
        funA(n/2);
    }
}


//NESTED  recursion: recursion inside recursion
int funcC(int n){
    if(n>100){
        return n-10;
    }
    else{
        return funcC(funcC(n+1));
    }
}

int main(){
    
    int x=20;
    funA(x);
    return 0;
}