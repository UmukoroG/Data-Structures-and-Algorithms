#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

string reverse(string s){
    int n=s.length();
    char ch[n+1];
    strcpy(ch, s.c_str());
    char s2[n+1];
    stack <char> rev;
    for(int i=0; i<n; i++){
        if(ch[i]!='\0'){
            rev.push(ch[i]);
        }
    }   
    int i=0;
    while(!rev.empty()){
        s2[i]=rev.top();
        rev.pop();
        i++;
    }
    return s2;
}

int main(){
    cout<<reverse("reverse");
    return 0;
}