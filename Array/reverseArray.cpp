#include <iostream>
using namespace std;

struct Array{
    int A[10];
    int size;
    int length;
};

void swap(int *x, int *y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

void display(struct Array arr){

    cout<<"\nElements are:\n";
    for(int i=0;i<arr.length;i++)
        cout<<arr.A[i] << " ";
    
}

//hard copying array values
void Reverse(struct Array *arr){
    int *B; //Auxilarry array
    int i,j;

    B= new int(arr->length);//creating array B in the heap
    for(int i=arr->length-1,j=0;i>=0;i--,j++){
        B[j]=arr->A[i];
    }
    for(int i=0;i<arr->length;i++){
        arr->A[i]=B[i];
    }
}

//swapping array values
void Reverse2(struct Array *arr){
    int i,j;
    for(i=0,j=arr->length-1; i<j; i++,j--){
        swap(&arr->A[i],&arr->A[j]);
    }
}



int main(){
    struct Array arr2={{2,3,5,6,7},10,5};
    Reverse2(&arr2);
    display(arr2);
    return 0;
}