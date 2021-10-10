#include <iostream>
using namespace std;

int fact(int);

int main(){
    cout<<fact(3);
    return 0;
}

int fact(int n){
    if(n==0 || n==1){
        return 1;
    }
    else
        return fact(n-1) * n;
}