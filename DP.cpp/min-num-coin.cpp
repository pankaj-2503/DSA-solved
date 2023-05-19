#include<bits/stdc++.h>
using namespace std;

class solution{
public:
  int solveRec(vector<int>&num,int x){
    //recursion->exponential time complexity
    if(x==0) return 0;
    if(x<0)  return INT_MAX;

    int mini=INT16_MAX;
    for(int i=0;i<num.size();i++){
        int ans=solveRec(num,x-num[i]);
        if(ans!=INT16_MAX)
           mini=min(mini,1+ans);
    }
    return mini;
  }

  int solveMem(vector<int>&num,int x,vector<int>&dp){
    //memoization
     if(x==0) return 0;
     if(x<0)  return INT_MAX;
     if(dp[x]!=-1) return dp[x];

     int mini=INT_MAX;
     for(int i=0;i<num.size();i++){
      int ans=solveMem(num,x-num[i],dp);
      if(ans!=INT_MAX) mini=min(mini,1+ans);
     }
     dp[x]=mini;
     return mini;

  }
  int solveTab(vector<int>&num,int x){
    //time complexity -O(x*n)
    //space complexity -O(x)
       vector<int>dp(x+1,INT_MAX);
       dp[0]=0;
       for(int i=1;i<=x;i++){
         //build solution for every amount of figure from 1 to x
         for(int j=0;j<num.size();j++){
          if(i-num[j]>=0 && dp[i-num[j]]!=INT_MAX){
            dp[i]=min(dp[i],1+dp[i-num[j]]);
          }
         }
       }
       if(dp[x]==INT_MAX) return -1;
       else return dp[x];
  }



  int miniElements(vector<int>&num,int x){
      // int ans=solveRec(num,x);
      // if(ans==INT_MAX) return -1;

      // return ans;
      

     // for memoization technique
      vector<int>dp(x+1,-1);
      int ans=solveMem(num,x,dp);
      if(ans=INT_MAX) return -1;
      else return ans;

      //tabulation 
      return solveTab(num,x);
  }
};