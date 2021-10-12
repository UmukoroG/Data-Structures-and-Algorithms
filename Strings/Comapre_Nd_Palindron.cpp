#include <iostream>
#include <cstring>
using namespace std;


bool compare(string s1, string s2){
    if(s1.length() != s2.length())
        return false;
    int n=s1.length();
    char ch1[n+1];
    char ch2[n+1];
    strcpy(ch1, s1.c_str());
    strcpy(ch2, s2.c_str());

    for(int i =0; i<n; i++){
        if(ch1[i] != ch2[i]){
            return false;
        }
    }
    return true;
}

// bool isPalindrone(string s){
    
// }


int main(){
    cout<<compare("madam madam onom","madam madam onom");
    return 0;
}