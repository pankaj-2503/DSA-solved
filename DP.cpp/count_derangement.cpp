#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    long long int solveMem(int n,vector<long long int>&dp){
        //time complexity-O(n),space complexity-O(n)+O(n)
        //memoization
        if(n==1) return 0;
        if(n==2) return 1;
        
        if(dp[n]!=-1) return dp[n];

        dp[n]=(n-1)*(countDerangement(n-1)+countDerangement(n-2));
        return dp[n];
    } 

    long long int solveTab(int n){
        //time complexity-O(n),space complexity-O(n)
        //tabulation
        vector<long long int>dp(n+1,-1);
        dp[1]=0;
        dp[2]=1;
        for(int i=3;i<=n;i++){
           long long int f=dp[i-1];
           long long int s=dp[i-2];
           long long int sum=f+s;
           long long int ans=((i-1)*sum);
           dp[i]=ans; 
        }
        return dp[n];

        //space optimisation technique;
        //time complexity-O(n),space complexity-O(1)
        long long int prev2=0;
        long long int prev1=1;
        for(int i=3;i<=n;i++){
           long long int f=prev1;
           long long int s=prev2;
           long long int sum=f+s;
           long long int ans=((i-1)*sum);
           prev2=prev1;
           prev1=ans;
        }
        return prev1;
    }

    int countDerangement(int n){
         //recursion method :exponential time complexity

         //base case

           if(n==1) return 0;
           if(n==2) return 1;

           int ans=(n-1)*(countDerangement(n-1)+countDerangement(n-2));
           return ans;

        //memoization soluton
        vector<long long int>dp(n+1,-1);
        return solveMem(n,dp);

    }
};