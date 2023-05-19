#include<bits/stdc++.h>
using namespace std;

int fib(int n,vector<int>&dp){
    //memoization
    
    //base case
    if(n<=1) return n;

    if(dp[n]!=-1) return dp[n];

    //storing dp or memoization
    dp[n]= fib(n-1,dp)+fib(n-2,dp);

    return dp[n];

}
//Time complexity-O(n);
//Space complexity-O(n) +O(n) ~ O(n);

int main(){
int n;
cout<<"enter the number :";cin>>n;
//top down approach:
vector<int>dp(n+1,-1);
cout<<"n-th fibonacci number"<<endl;
cout<<fib(n,dp)<<endl;
/*
or we can do bottom-up approach:
Tabulation

Time complexity- O(n)
Space complexity-  O(n)

int n;cin>>n;
vector<int>dp(n+1);
dp[1]=1;
dp[0]=0;

for(int i=2;i<=n;i++){
    dp[i]=dp[i-1]+dp[i-2];
}
cout<<dp[n];



*/

/*

or space optimisation:

Time complexity-O(n)
Space complexity-O(1)

int n;cin>>n;
int prev1=0;
int prev2=1;

if(n==0) return prev2;

for(int i=2;i<=n;i++){
    int curr=prev1+prev2;
    //shift pointers
    prev2=prev1;
    prev1=curr;
}

cout<<prev1<<endl;

*/

return 0;
}