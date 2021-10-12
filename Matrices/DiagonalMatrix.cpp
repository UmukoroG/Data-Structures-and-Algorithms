#include <iostream>
#include <cstring>
using namespace std;

class Diagonal{
    private:
        int n;
        int *A;
    public:
        Diagonal(){
            n=2;
            A=new int[2];
        }
        Diagonal(int n){
            this->n=n;
            A=new int[n];
        }
        void Set(int row, int col, int x);
        int Get(int i, int j);
        void Display();
        ~Diagonal(){
            delete []A;
        }
};

void Diagonal::Set(int i, int j, int x){
    if(i==j){
        A[i-1]=x;
    }
}

int Diagonal::Get(int i, int j){
    if(i==j){
        return A[i-1];
    }
    else{
        return 0;
    }
}

void Diagonal::Display(){
    int i, j;
    for(i =0; i<n;i++){
        for(j=0;j<n;j++){
            if(i==j){
                cout<<A[i] <<" ";
            }
            else{
                cout<<0 <<" ";
            }
        }
        cout<<endl;
    }

}

int main(){
    int n=4;//4 X 4 matrice
    Diagonal m(n);

    m.Set(1,1,5); 
    m.Set(2,2,8); 
    m.Set(3,3,9);
    m.Set(4,4,12);
    cout<<m.Get(2,2)<<endl;
    m.Display();

    return 0;
}