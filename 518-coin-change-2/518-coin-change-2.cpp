class Solution {
public:
    // top-down striver
    int solve(int ind,int sum,vector<int> &a,vector<vector<int>> &dp){
        if(ind==0){
            if(sum%a[0]==0)return 1;
            else return 0;
        }
        if(dp[ind][sum]!=-1)return dp[ind][sum];

        int nottake = solve(ind-1,sum,a,dp);
        int take = 0;
        if(a[ind]<=sum)take = solve(ind,sum-a[ind],a,dp);

        return dp[ind][sum] = take + nottake;
    }

    // same question as count subsets sum -> with infinite supply of items
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return solve(n-1,amount,coins,dp);
    }
};