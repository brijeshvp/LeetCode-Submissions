class Solution {
public:
    // top-down striver
    int solve(int ind,int canBuy,vector<int> &prices,vector<vector<int>> &dp){
        int n = prices.size();
        if(ind==n)return 0;
        if(dp[ind][canBuy]!=-1)return dp[ind][canBuy];
        
        int profit = 0;
        if(canBuy){
            int buy = -prices[ind] + solve(ind+1,0,prices,dp);
            int notbuy = 0 + solve(ind+1,1,prices,dp);
            profit = max(buy,notbuy);
        }
        else{
            int sell = prices[ind] + solve(ind+1,1,prices,dp);
            int notsell = 0 + solve(ind+1,0,prices,dp);
            profit = max(sell,notsell);
        }
        return dp[ind][canBuy] = profit;
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0,1,prices,dp);
    }
};