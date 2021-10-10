#include <iostream>
#include <vector>
using namespace std;

int sum(int);

int main(){
    cout<<sum(5);

    return 0;
}

//sum of first 'n' Natural numbers
int sum(int n){
    int count;
    if(n==0){
        return 0;
    }
    return sum(n-1)+n;
}