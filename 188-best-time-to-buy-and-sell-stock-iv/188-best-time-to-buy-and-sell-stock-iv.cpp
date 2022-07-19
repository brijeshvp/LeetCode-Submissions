class Solution {
public:
    // copy paste method-2 of stocks-3 problem(all three version -> top-down, bottom-up and bottom-up + space-optimization) -> just k = 2(fixed) in stocks-3, here k is given to us -> that's it!
//     // top-down striver
//     // TC: O(n*4) and SC: O(n*4) + O(n) -> dp array + call stack
//     int solve(int ind,int transactions,vector<int> &prices,vector<vector<int>> &dp,int k){
//         int n = prices.size();
//         if(ind==n || transactions==2*k)return 0;
//         if(dp[ind][transactions]!=-1)return dp[ind][transactions];
        
//         int profit = 0;
//         if(transactions%2==0){
//             int buy = -prices[ind] + solve(ind+1,transactions+1,prices,dp,k);
//             int notbuy = 0 + solve(ind+1,transactions,prices,dp,k);
//             profit = max(buy,notbuy);
//         }
//         else{
//             int sell = prices[ind] + solve(ind+1,transactions+1,prices,dp,k);
//             int notsell = 0 + solve(ind+1,transactions,prices,dp,k);
//             profit = max(sell,notsell);
//         }
//         return dp[ind][transactions] = profit;
//     }
    
//     int maxProfit(int k, vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<int>> dp(n,vector<int>(2*k,-1));
//         return solve(0,0,prices,dp,k);
//     }
    
    
    
    
    
     // bottom-up striver
    // TC: O(n*4) and SC: O(n*4)
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2*k+1,0));
        
        for(int ind=n-1;ind>=0;--ind){
            for(int tranNo=2*k-1;tranNo>=0;--tranNo){
                int profit = 0;
                if(tranNo%2==0){
                    int buy = -prices[ind] + dp[ind+1][tranNo+1];
                    int notbuy = 0 + dp[ind+1][tranNo];
                    profit = max(buy,notbuy);
                }
                else{
                    int sell = prices[ind] + dp[ind+1][tranNo+1];
                    int notsell = 0 + dp[ind+1][tranNo];
                    profit = max(sell,notsell);
                }
                dp[ind][tranNo] = profit;
            }
        }
        return dp[0][0];
    }
};