#include <iostream>
#include <vector>
using namespace std;

int max(int a, int b){
    return (a>b) ? a : b;
}

//Recursion: O(2^n)
int RknapSack(int w, int wt[], int p[], int n){
    if(n==0 || w==0) return 0;

    if(wt[n-1]>w){
        return RknapSack(w, wt, p, n-1);
    }

    else{
        return max(
            p[n-1]+RknapSack(w-wt[n-1],wt,p,n-1),
            RknapSack(w, wt, p,n-1)
        );
    }


}

//Dynamic Programming
int DpKnapSack(int w, int wt[], int p[], int n){
    int i, j;

    vector<vector<int>> K(n+1,vector<int>(w+1));

    // Build table K[][] in bottom up manner
    for(i=0; i<=n;i++){
        for(j=0;j<=w;j++){
            if(i==0 || j==0)
                K[i][j]=0;
            else if(wt[i-1]<=j)
                K[i][j]=max(p[i-1]+K[i - 1][j - wt[i - 1]],K[i - 1][j]);
            else   
                K[i][j]=K[i-1][j];
        }
    }
    return K[n][w];
}

int main(){
    int profit[]={1,2,5,6};
    int wt[]={2,3,4,5};

    int w=8;//max weight
    int n=sizeof(profit)/sizeof(profit[0]);

    cout<<DpKnapSack(w,wt,profit,n);

    return 0;
}