#include <iostream>
using namespace std;

struct Array{
    int A[10];
    int size;
    int length;
};


void display(struct Array arr){

    cout<<"\nElements are:\n";
    for(int i=0;i<arr.length;i++)
        cout<<arr.A[i] << " ";
    
}

struct Array* Merge(struct Array *arr1 , struct Array *arr2){
    int i , j , k;
    i=j=k=0;
    struct Array *arr3;
    arr3->size=10;
    // arr3->A=new int(arr3->size);

    while(i<arr1->length && j<arr2->length){
        //compare and copy elements
        if(arr1->A[i]<arr2->A[j]){
            arr3->A[k++]=arr1->A[i++];
        }
        else{
            arr3->A[k++]=arr2->A[j++];
        }
    }
    for(; i<arr1->length;i++){
        arr3->A[k++]=arr1->A[i];
    }
    for(; j<arr1->length;j++){
        arr3->A[k++]=arr2->A[j];
    }
    arr3->length=arr1->length + arr2->length;

    return arr3;
    arr3->size=10;


}


int main(){
    struct Array arr1={{2,6,10,15,25},10,5};
    struct Array arr2={{3,4,7,18,20},10,5};
    struct Array *arr3;
    arr3=Merge(&arr1,&arr2);
    display(*arr3);
    return 0;
}