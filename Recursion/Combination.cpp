#include <iostream>
using namespace std;

int C1(int , int);
int fact(int);
int C(int , int);

int main(){
    cout<<C(5,3);
    cout<<endl;
    cout<<C1(5,3);

    return 0;
}

int C(int n, int r){
    int num, den;
    num=fact(n);
    den=fact(r)*fact(n-r);

    return num/den;
}

int C1(int n, int r){//using Pascal Triangle //faster
    if(r==0 || n==r){
        return 1;
    }
    return C1(n-1,r-1)+C1(n-1,r);
}

int fact(int n){
    if(n==0 || n==1){
        return 1;
    }
    else
        return fact(n-1) * n;
}