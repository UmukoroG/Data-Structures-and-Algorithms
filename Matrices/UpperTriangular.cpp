#include <iostream>
#include <cstring>
using namespace std;

//USING ROW-MAJOR MAPPING

class UpperTriangular{
    private:
        int n;
        int *A;
    public:
        UpperTriangular(){
            n=2;
            A=new int[2*(2+1)/2];
        }
        UpperTriangular(int n){
            this->n=n;
            A=new int[n*(n+1)/2];
        }
        void Set(int row, int col, int x);
        int Get(int i, int j);
        void Display();
        int GetDimension(){
            return n;
        }
        ~UpperTriangular(){
            delete []A;
        }
};

void UpperTriangular::Set(int i, int j, int x){
    if(i>=j){
        A[(j*(j-1)/2) + i-1]=x;
    }
}

int UpperTriangular::Get(int i, int j){
    if(i==j){
        return A[(j*(j-1)/2) + i-1];
    }
    else{
        return 0;
    }
}

void UpperTriangular::Display(){
    int i, j;
    for(i =1; i<=n;i++){
        for(j=1;j<=n;j++){
            if(i<=j){
                cout<<A[(j*(j-1)/2) + i-1] <<" ";
            }
            else{
                cout<<0 <<" ";
            }
        }
        cout<<endl;
    }

}

int main(){
    int n;
    cout<<"Enter the dimension:";
    cin>>n;
    UpperTriangular m(n);

    int x;
    cout<<"Enter All Elements:\n";
    for(int i=1; i<=n; i++){
        for(int j=1;j<=n;j++){
            cin>>x;
            m.Set(i,j,x);
        }
    }
    cout<<endl;
    m.Display();

    return 0;
}