class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        
        int dp[n+1][amount+1];
        // initializing 0th row
        for(int j=1;j<amount+1;++j)dp[0][j] = INT_MAX-1;
        // initializing 0th col
        for(int i=1;i<n+1;++i)dp[i][0] = 0;
        dp[0][0] = INT_MAX-1;   // very imp step(understand properly)
        
        // intializing 1st row  ->  i=1 -> 1st denomination of coin = coin[0]
        for(int j=1;j<amount+1;++j){
            if(j%coins[0]==0)dp[1][j] = j/coins[0];     // can make given amount with 1st coin
            else dp[1][j] = INT_MAX-1;  // can't make given amount with 1st coin
        }
        
        
        // initialization done....
        
        
        for(int i=2;i<n+1;++i){
            for(int j=1;j<amount+1;++j){
                if(coins[i-1]<=j){
                    dp[i][j] = min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
                }
                else if(coins[i-1]>j){
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        int ans = dp[n][amount];
        return (ans==INT_MAX-1)?-1:ans;
    }
};