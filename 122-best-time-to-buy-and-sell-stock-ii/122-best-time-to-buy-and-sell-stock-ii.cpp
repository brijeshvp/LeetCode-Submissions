class Solution {
public:
//     // top-down striver
//     int solve(int ind,int canBuy,vector<int> &prices,vector<vector<int>> &dp){
//         int n = prices.size();
//         if(ind==n)return 0;
//         if(dp[ind][canBuy]!=-1)return dp[ind][canBuy];
        
//         int profit = 0;
//         if(canBuy){
//             int buy = -prices[ind] + solve(ind+1,0,prices,dp);
//             int notbuy = 0 + solve(ind+1,1,prices,dp);
//             profit = max(buy,notbuy);
//         }
//         else{
//             int sell = prices[ind] + solve(ind+1,1,prices,dp);
//             int notsell = 0 + solve(ind+1,0,prices,dp);
//             profit = max(sell,notsell);
//         }
//         return dp[ind][canBuy] = profit;
//     }
    
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<int>> dp(n,vector<int>(2,-1));
//         return solve(0,1,prices,dp);
//     }
    
    
    
    
    
    
    // bottom-up striver
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        
        dp[n][0] = dp[n][1] = 0;
        
        for(int ind=n-1;ind>=0;--ind){
            for(int canBuy=0;canBuy<=1;++canBuy){
                int profit = 0;
                if(canBuy){
                    int buy = -prices[ind] + dp[ind+1][0];
                    int notbuy = 0 + dp[ind+1][1];
                    profit = max(buy,notbuy);
                }
                else{
                    int sell = prices[ind] + dp[ind+1][1];
                    int notsell = 0 + dp[ind+1][0];
                    profit = max(sell,notsell);
                }
                dp[ind][canBuy] = profit;
            }
        }
        return dp[0][1];    // at 0th ind -> we can always buy -> 2nd parameter = 1, also we run from n-1 to 0 -> so at last we return dp[0][1]
    }
};