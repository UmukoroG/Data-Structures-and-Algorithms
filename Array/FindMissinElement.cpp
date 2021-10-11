#include <iostream>
#include <vector>
using namespace std;


void display(vector<int> nums){

    cout<<"\nElements are:\n";
    for(int i=0;i<nums.size();i++)
        cout<<nums[i] << " ";
    
}

int min(vector<int>& nums){ 
    int min=nums[0];
    for(int i=0; i<nums.size();i++){
        if(nums[i]<min){
            min=nums[i];
        }
    }
    return min;
}

int max(vector<int>& nums){  
    int max=nums[0];
    for(int i=0; i<nums.size();i++){
        if(nums[i]>max){
            max=nums[i];
        }
    }
    return max;
}
void missingNumber(vector<int>& nums) {
    int l=min(nums);
    int n=l;
    int h=max(nums);
    
    vector<int> H;
    for(int i=0; i<n;i++){
        H[i]=0;
    }
    for(int i=0; i<n; i++){
        H[nums[i]]++;
    }
    
    for(int i=l ;i<h;i++){
        if(H[i]==0){
            cout<<i;
            
        }
    }
    
    
}


int main(){
    vector<int> arr={1,2,3,6,7,10,21,12};
    display(arr);
    cout<<endl<< min(arr)<<endl<<max(arr)<<endl;
    missingNumber(arr);
    return 0;
}