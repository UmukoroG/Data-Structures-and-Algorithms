#include <iostream>
using namespace std;

void TOH(int,int, int , int);

int main(){
    int A=1,B=2,C=3;
    TOH(2,A,B,C);
    return 0;
}

void TOH(int n, int A, int B, int C){
    if(n>0){ //time: O(2^n) 
        TOH(n-1,A,C,B);
        cout<<A<<","<<C;
        cout<<endl;
        TOH(n-1,B,A,C);
    }
}

