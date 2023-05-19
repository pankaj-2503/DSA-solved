#include<bits/stdc++.h>
using namespace std;

class solution{

public:
int  solve(vector<int>&cost,int n){
    
    if(n==0) return cost[0];
    if(n==1) return cost[1];

    int ans=cost[n]+ min(solve(cost,n-1),solve(cost,n-2));
    return ans;
}
int solve2(vector<int>&cost,int n,vector<int>&dp){
    //top down approach
     if(n==0) return cost[0];
    if(n==1) return cost[1];
    

    //memoization
    if(dp[n]!=-1) return dp[n];

    dp[n]=cost[n]+ min(solve2(cost,n-1,dp),solve2(cost,n-2,dp));
    return dp[n];
}

int solve3(vector<int>&cost,int n){
    //bottom-up 
    //time complexity-O(n),space complexity-O(n)
    vector<int>dp(n+1);
    dp[0]=cost[0];
    dp[1]=cost[1];

    for(int i=2;i<=n-1;i++){
        dp[i]=cost[i]+ min(dp[i-1],dp[i-2]);
    }
    return min(dp[n-1],dp[n-2]); 
}
int solve4(vector<int>&cost,int n){
    //time complexity-O(n),space complexity-O(1)
    int prev2=cost[0];
    int prev1=cost[1];

    for(int i=2;i<n;i++){
        int curr=cost[i]+min(prev1,prev2);
        prev2=prev1;
        prev1=curr;
    }
    return min(prev1,prev2);
    
}


int mincostClimbingStairs(vector<int>&cost){
    //method :1 but TLE
    // int n=cost.size();
    // int ans=min(solve(cost,n-1),solve(cost,n-2));
    // return ans;

    //method:2 adding memoization

    // int n=cost.size();
    // vector<int>dp(n+1,-1);
    // int ans=min(solve2(cost,n-1,dp),solve2(cost,n-2,dp));
    // return ans;

    // //method:3 bottom-up
    // int n=cost.size();
    // return solve3(cost,n);
   
    //space optimised
    int n=cost.size();
    return solve4(cost,n);


}


};