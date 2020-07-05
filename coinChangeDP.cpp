/*
Given an infinite supply of ‘n’ coin denominations and a total money amount, we are asked to find the total number of distinct ways to make up that amount.

Example:

Denominations: {1,2,3}
Total amount: 5
Output: 5
Explanation: There are five ways to make the change for '5', here are those ways:
  1. {1,1,1,1,1} 
  2. {1,1,1,2} 
  3. {1,2,2}
  4. {1,1,3}
  5. {2,3}
Problem Statement #
Given a number array to represent different coin denominations and a total amount ‘T’, we need to find all the different ways to make a change for ‘T’ with the given coin denominations. We can assume an infinite supply of coins, therefore, each coin can be chosen multiple times.

This problem follows the Unbounded Knapsack pattern.

*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int N = coins.size();
        if(!N)
        {
            if(!amount) 
                return 1;
            else
                return 0;
        }
        vector<vector<int>> DP(N,vector<int>(amount+1,0));
        DP[0][0] = 1;
        
        for(int i=0; i < N; i++)
            DP[i][0] = 1;
        
        for(int n=0; n<N; n++)
        {
            for(int s=1; s < amount+1; s++)
            {
                if(n > 0)
                    DP[n][s] = DP[n-1][s];
                
                if(s >= coins[n])
                    DP[n][s] += DP[n][s-coins[n]];//max(DP[n-1][s], 1+DP[n][s-coins[n]]);
                //else
                //    DP[n][s] = DP[n-1][s];
            }
        }
        return DP[N-1][amount];
    }
};
