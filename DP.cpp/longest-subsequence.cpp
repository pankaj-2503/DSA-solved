#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    int solve(int a[], int n, int curr, int prev)
    {
        // base case
        if (curr == n)
            return 0;
        // include
        int take = 0;
        if (prev == -1 || a[curr] > a[prev])
            take = 1 + solve(a, n, curr + 1, curr); // as prev will move to curr position
        // exclude
        int notTake = 0 + solve(a, n, curr + 1, prev); // prev will not move as not exclude so only curr will move
        return max(take, notTake);
    }

    int solveMem(int a[], int n, int curr, int prev, vector<vector<int>> &dp)
    {
        // base case
        if (curr == n)
            return 0;

        // dp condition
        if (dp[curr][prev + 1] != -1)
            return dp[curr][prev + 1];
        // include
        int take = 0;
        if (prev == -1 || a[curr] > a[prev])
            take = 1 + solveMem(a, n, curr + 1, curr, dp); // as prev will move to curr position
        // exclude
        int notTake = 0 + solveMem(a, n, curr + 1, prev, dp);
        return dp[curr][prev + 1] = max(take, notTake); // as there is no negative indexing
    }

    int solveTab(int n, int a[])
    {  //time and space -O(n^2) & O(n^2)
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int curr = n - 1; curr >= 0; curr--)
        {
            for (int prev = curr - 1; prev >= -1; prev--)
            {
                int take = 0;
                // include
                if (prev == -1 || a[curr] > a[prev])
                    take = 1 + dp[curr + 1][curr + 1]; // as prev will move to curr position so we will move backward to prev will be incremented in this case
                                                       // exclude
                int notTake = 0 + dp[curr + 1][prev + 1];
                dp[curr][prev + 1] = max(take, notTake);
            }
        }
        return dp[0][0];
    }

     int solveSO(int n, int a[])
    {  //time and space -O(n^2) & O(n^2)
        vector<int>currrow(n+1,0);
        vector<int>nextrow(n+1,0);
        for (int curr = n - 1; curr >= 0; curr--)
        {
            for (int prev = curr - 1; prev >= -1; prev--)
            {
                int take = 0;
                // include
                if (prev == -1 || a[curr] > a[prev])
                    take = 1 + nextrow[curr + 1]; // as prev will move to curr position so we will move backward to prev will be incremented in this case
                                                       // exclude
                int notTake = 0 + nextrow[prev + 1];
                currrow[prev + 1] = max(take, notTake);
            }
            nextrow=currrow;  //move next to curr
        }
        return  nextrow[0];
    }

    int longestSubsequence(int a[], int n)
    {
        // recursion
        return solve(a, n, 0, -1); // intially prev as -1

        // memoization
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solveMem(a, n, 0, -1, dp);
        // tabulation
        return solveTab(n, a);
        //space optimisation
        return solveSO(n,a);
    }
};