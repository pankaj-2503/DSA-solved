#include<bits/stdc++.h>
using namespace std;

class solution{
    public:
    int solve(int n){
        //base case
         if(n==0) return 0;

         int ans=n;
         for(int i=1;i<=sqrt(n);i++){
            ans=min(ans,1+solve(n-i*i));
         }
         return ans;
    }
    int solveMem(int n,vector<int>&dp){
        //base case
        if(n==0) return 0;

        if(dp[n]!=-1) return dp[n]; 

        int ans=n;
        for(int i=1;i<=sqrt(n);i++){
            ans=min(ans,1+solveMem(n-i*i,dp));
        }
        dp[n]=ans;
        return dp[n];
    }

    int solveTab(int n){
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0;
       for(int i=1;i<=n;i++){
          for(int j=1;j<=sqrt(n);j++){
            if(i-j*j>=0)
             dp[i]=min(dp[i],1+dp[i-j*j]);
          }
       }
       return dp[n]; 
    }

    int minSquares(int n){
        //recursion
        return solve(n);
        //memoization
        vector<int>dp(n+1,-1);
        return solveMem(n,dp);
        //tabulation
        return solveTab(n);
        //no space optimisation

    }
};