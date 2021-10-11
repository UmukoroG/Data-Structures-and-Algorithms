#include <iostream>
using namespace std;

struct Array{
    int *A;
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

int Sum(struct Array arr){
    int s=0;
    int i;
    for(i=0;i<arr.length;i++)
    s+=arr.A[i];

    return s;
}

void InsertSort(struct Array *arr, int x){
    int i=arr->length-1;
    if(arr->length==arr->size){
        return;
    }
    while( i>=0 && arr->A[i]>x){
        arr->A[i+1]=arr->A[i];
        i--;
    }
    arr->A[i+1]=x;
    arr->length++;
}

int isSorted(struct Array arr){

    int i;
    for(i=0;i<arr.length-1;i++){
        if(arr.A[i]>arr.A[i+1])
            return 0;//false-not sorted
    }
    return 1;//true-sorted
}

// void Rearrange(struct Array *arr){
//     int i, j;
//     i=0;
//     j=arr->length-1;
//     while(i<j){
//         while(arr->A[i]<0){
//             i++;
//         }
//         while(arr->A[i]>=0){
//             j--;
//         }
//         if(i<j){ 
//             swap(&arr->A[i],&arr->A[j]);
//         }
//     }
// }

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

struct Array* Union(struct Array *arr1 , struct Array *arr2){
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
        else if(arr2->A[j]<arr1->A[i]){
            arr3->A[k++]=arr2->A[j++];
        }
        else{//if both are equal : UNION, copy either one and increment both index
            arr3->A[k++]=arr1->A[i++];
            j++;
        }
    }
    for(; i<arr1->length;i++){
        arr3->A[k++]=arr1->A[i];
    }
    for(; j<arr1->length;j++){
        arr3->A[k++]=arr2->A[j];
    }

    arr3->length=k;
    // arr3->size=10;
    return arr3;

}

struct Array* Intersection(struct Array *arr1 , struct Array *arr2){
    int i , j , k;
    i=j=k=0;
    struct Array *arr3;
    arr3->size=10;
    

    while(i<arr1->length && j<arr2->length){
        
        if(arr1->A[i]<arr2->A[j]){
            i++;
        }
        else if(arr2->A[j]<arr1->A[i]){
            j++;
        }
        else if(arr1->A[i]==arr2->A[j]){//both elements are equal: Intersection
            arr3->A[k++]=arr1->A[i++];
            j++;
        }
    }

    arr3->length=k;
    // arr3->size=10;
    return arr3;

}


struct Array* Diff(struct Array *arr1 , struct Array *arr2){
    int i , j , k;
    i=j=k=0;
    struct Array *arr3;
    arr3->size=10;
    

    while(i<arr1->length && j<arr2->length){
        //compare first Array element to copy
        if(arr1->A[i]<arr2->A[j]){
            arr3->A[k++]=arr1->A[i++];
        }
        //skip
        else if(arr2->A[j]<arr1->A[i]){
            j++;
        }
        //skip
        else{ //if equal, increment i and j
            i++;
            j++;
        }
    }
    //copy remaining element of array 1
    for(; i<arr1->length;i++){
        arr3->A[k++]=arr1->A[i];
    }
    
    arr3->length=k;
    // arr3->size=10;
    return arr3;

}


int main(){
    struct Array arr1;
    int ch;
    int x,index;
    // int n;//length of the array
    int size= arr1.size*sizeof(int);
    cout<<"Enter the size of the array:" ;
    cin>>arr1.size;

    arr1.A=new int(size);
    
    do{
    cout<<"\n\nMenu\n";
    cout<<"1. Insert\n";
    cout<<"2. Delete\n";
    cout<<"3. Search\n";
    cout<<"4. Sum\n";
    cout<<"5. Display\n";
    cout<<"6.Exit\n";

    cout<<"enter you choice ";
    cin>>ch;

    switch(ch){
            case 1: cout<<"Enter an element and index";
                cin>>x,index;
                Insert(&arr1,index,x);
                break;
            case 2: cout<<"Enter index ";
                cin>>index;
                x=Delete(&arr1,index);
                cout<<"Deleted Element is \n"<<x;
                break;
            case 3:cout<<"Enter element to search ";
                cin>>x;
                index=LinearSearch(&arr1,x);
                cout<<"Element index"<<index;
                break;
            case 4:
                cout<<"Sum is \n"<<Sum(arr1);
                break;
            case 5:
                display(arr1);

    }
    }while(ch<6);

    return 0;
} 