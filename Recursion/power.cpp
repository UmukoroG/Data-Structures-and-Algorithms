#include <iostream>
using namespace std;

int pow(int, int);
int pow1(int, int);

int main(){

    cout<<pow1(5,2);
    return 0;
}

int pow(int m, int n){
    if(m==0){
        return 0;
    }
    if(n==0){
        return 1;
    }
    return pow(m,n-1)*m;
}

int pow1(int m, int n){
    if(m<=0){
        cout<<"m cannot be less than or equal ";
        return 0;
    }
    if(n==0){
        return 1;
    }
    if(n%2==0){
        return pow(m*m,n/2);
    }
    return m*pow(m*m,(n-1)/2);
}