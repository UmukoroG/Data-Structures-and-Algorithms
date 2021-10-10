#include <iostream>
using namespace std;

// struct Array{
//     int *A;//The array space is in the heap memory 
//     int size;
//     int length;
// };

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

void Append(struct Array *arr, int x){
    //we use arrow because we are calling by address
    if(arr->length<arr->size){//if length < size
        arr->A[arr->length++]=x;
    }
}

//Move the element before index forward then insert
void Insert(struct Array *arr, int index, int x){
    if(index>=0 && index <= arr->length){
        //shifts the elements and provide a free space
        for(int i=arr->length; i>index;i--){
            arr->A[i]=arr->A[i-1];
        }
        arr->A[index]=x;
        arr->length++;
    }
}

//Delete index then move element after index backward 
int Delete(struct Array *arr, int index){
    int x=0;
    if(index>=0 && index <= arr->length){
        x=arr->A[index];
        for(int i=index; i<arr->length-1;i++){
            arr->A[i]=arr->A[i+1];
        }
        arr->length--;
        return x;
    
    }

    return 0;//if index is invalid
}

void swap(int *x, int *y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

int LinearSearch(struct Array *arr, int value){
    for(int i=0;i<arr->length;i++){
        if(value==arr->A[i]){
            swap(&arr->A[i],&arr->A[i-1]);//transposition
            // swap(&arr->A[i],&arr->A[0]);//move to head
            return i;
        }
    }
    return -1;//not found
}

int BinarySearch(struct Array arr, int key){
    int l,mid,h;
    l=0;
    h=arr.length-1;

    while(l<=h){
        mid=(l+h)/2;
        if(key==arr.A[mid])
            return mid;
        else if(key<arr.A[mid]){
            h=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return -1;
}

//Takes more space in the stack and slower than it's iterative counter part
int RBinSearch(int a[], int l, int h, int key){
    int mid;

    if(l<=h){
        mid=(l+h)/2;
        if(key==a[mid]){
            return mid;
        }
        else if(key<a[mid]){
            return RBinSearch(a,l,mid-1, key);
        }
        else{
            return RBinSearch(a,mid+1,h,key);
        }
    }
    return -1;
}

int main(){
    
    // struct Array arr;
    // int n;//length of the array
    // int size= arr.size*sizeof(int);
    // cout<<"Enter the size of the array:" ;
    // cin>>arr.size;

    // arr.A=new int(size);
    // arr.length=0;
    
    // cout<<"Enter the number of elements be added:";
    // cin>>n;

    // cout<<"Enter all Elements\n";
    // for(int i=0;i<n;i++){
    //    cin>>arr.A[i]; 
    // }

    // arr.length=n;

    // display(arr);

    cout<<endl;
    struct Array arr2={{2,3,5,6,7},10,5};
    // Append(&arr2, 10);
    // Insert(&arr2,2,9);
    // display(arr2);
    // cout<<Delete(&arr2,0)<<endl;
    display(arr2);
    cout<<endl;
    // cout<<LinearSearch(&arr2,6)<<endl;
    // cout<<BinarySearch(arr2,5);
    cout<<RBinSearch(arr2.A,0,arr2.length,5);
    display(arr2);

    return 0;
}