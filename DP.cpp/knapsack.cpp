#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    int solve(vector<int> &weight, vector<int> &value, int index, int capacity)
    {
        // base case
        //  if only 1 item to steal,then just compare its weight with the knapsack capacity
        // traversing from backside
        if (index == 0)
        {
            if (weight[0] <= capacity)
            {
                return weight[0];
            }
            else
                return 0;
        }
        // include
        int include = 0;
        if (weight[index] <= capacity)
        {
            include = value[index] + solve(weight, value, index - 1, capacity - weight[index]);
        }
        // exclude
        int exclude = 0 + solve(weight, value, index - 1, capacity);
        int ans = max(include, exclude);
        return ans;

        // as recursive solution to it will give TLE
    }

    int solveMem(vector<int> &weight, vector<int> &value, int index, int capacity, vector<vector<int>> &dp)
    {
        // base case
        //  if only 1 item to steal,then just compare its weight with the knapsack capacity
        // traversing from backside
        if (index == 0)
        {
            if (weight[0] <= capacity)
            {
                return weight[0];
            }
            else
                return 0;
        }

        if (dp[index][capacity] != -1)
            return dp[index][capacity];
        // include
        int include = 0;
        if (weight[index] <= capacity)
        {
            include = value[index] + solveMem(weight, value, index - 1, capacity - weight[index], dp);
        }
        // exclude
        int exclude = 0 + solveMem(weight, value, index - 1, capacity, dp);
        dp[index][capacity] = max(include, exclude);
        return dp[index][capacity];

        // as recursive solution to it will give TLE
    }

    int solveTab(vector<int> &weight, vector<int> &value, int n, int capacity)
    {
        // step : 1
        vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));
        // step:2 analyse base case

        for (int w = weight[0]; w <= capacity; w++)
        {
            if (weight[0] <= capacity)
            {
                dp[0][w] = value[0];
            }
            else
                dp[0][w] = 0;
        }
       //take care of remaining recursive calls
        for (int index = 1; index < n; index++)
        {
            for (int w = 0; w <= capacity; w++)
            {
                int include = 0;
                if (weight[index] <= w)
                {
                    include = value[index] +dp[index - 1][w - weight[index]];
                }
                // exclude
                int exclude = 0 +dp[index - 1][w];
                dp[index][w] = max(include, exclude);
                
            }
        }
        return dp[n-1][capacity];
    }
     int solveSO(vector<int> &weight, vector<int> &value, int n, int capacity)
    {
        //space optimisation
        // step : 1
       vector<int>prev(capacity+1,0);
       vector<int>curr(capacity+1,0);

        for (int w = weight[0]; w <= capacity; w++)
        {
            if (weight[0] <= capacity)
            {
                prev[w] = value[0];
            }
            else
                prev[0][w] = 0;
        }
       //take care of remaining recursive calls
        for (int index = 1; index < n; index++)
        {
            for (int w = 0; w <= capacity; w++)
            {
                int include = 0;
                if (weight[index] <= w)
                {
                    include = value[index] + prev[w - weight[index]];
                }
                // exclude
                int exclude = 0 + prev[index - 1][w];
                curr[w] = max(include, exclude);
                
            }
            prev=curr;
        }
        return prev[capacity];
    }


    int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
    {
        // recursive
        return solve(weight, value, n - 1, maxWeight);

        // memoization
        vector<vector<int>> dp(n, vector<int>(maxWeight, -1));
        return solveMem(weight, value, n - 1, maxWeight, dp);

        //tabulation
        return solveTab(weight,value,n,maxWeight);
    }
};