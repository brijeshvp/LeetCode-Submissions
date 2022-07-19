class Solution {
public:
    // 3d dp
    
    // top-down striver
    // TC: O(n*2*3) and SC: O(n*2*3) + O(n) -> dp array + call stack
    int solve(int ind,int canBuy,int capacity,vector<int> &prices,vector<vector<vector<int>>> &dp){
        int n = prices.size();
        if(ind==n || capacity==0)return 0;
        if(dp[ind][canBuy][capacity]!=-1)return dp[ind][canBuy][capacity];
        
        int profit = 0;
        if(canBuy){
            int buy = -prices[ind] + solve(ind+1,0,capacity,prices,dp);
            int notbuy = 0 + solve(ind+1,1,capacity,prices,dp);
            profit = max(buy,notbuy);
        }
        else{
            int sell = prices[ind] + solve(ind+1,1,capacity-1,prices,dp);
            int notsell = 0 + solve(ind+1,0,capacity,prices,dp);
            profit = max(sell,notsell);
        }
        return dp[ind][canBuy][capacity] = profit;
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(0,1,2,prices,dp);
    }
};