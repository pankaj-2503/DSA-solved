#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class solution{
public:
  
  int solve(vector<int>num,int n){
    //base case
     if(n<0) return 0;
     if(n==0) return num[0];

     int exc=solve(num,n-2)+num[n];
     int inc=solve(num,n-1)+0;

     return max(exc,inc);
  }
  int solveMem(vector<int>&num,int  n,vector<int>&dp){
     if(n<0) return 0;
     if(n==0) return num[0];
     //memoization
     if(dp[n]!=-1) return dp[n];
      int exc=solveMem(num,n-2,dp)+num[n];
     int inc=solveMem(num,n-1,dp)+0;

     dp[n]=max(exc,inc);
     return dp[n];

  }

  int solveTab(vector<int>&num){
    int n=num.size();
    vector<int>dp(n,0);
    dp[0]=num[0];
    for(int i=1;i<n;i++){
        int inc=dp[i-2]+num[i];
        int exc=dp[i-1]+0;
        dp[i]=max(inc,exc);
    }
    return dp[n-1];
  }
  int spaceOptimisation(vector<int>&num){
    int n=num.size();
    
    int prev1=0;
    int prev2=num[0];
    for(int i=1;i<n;i++){
        int inc=prev2+num[i];
        int exc=prev1+0;
        int ans=max(inc,exc);
        prev2=prev1;
        prev1=ans;
    }
    return prev1;
  }

  int maximumNonAdjacentsum(vector<int>&num){
      int n=num.size();
      int ans=solve(num,n-1);
      return ans;

      //memoization
      int n=num.size();
      vector<int>dp(n,-1);
      return solveMem(num,n-1,dp);
      //tabulation
      return solveTab(num);
  }
};