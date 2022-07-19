class Solution {
public:
    // method-1 : 3d dp striver
    
//     // top-down striver
//     // TC: O(n*2*3) and SC: O(n*2*3) + O(n) -> dp array + call stack
//     int solve(int ind,int canBuy,int capacity,vector<int> &prices,vector<vector<vector<int>>> &dp){
//         int n = prices.size();
//         if(ind==n || capacity==0)return 0;
//         if(dp[ind][canBuy][capacity]!=-1)return dp[ind][canBuy][capacity];
        
//         int profit = 0;
//         if(canBuy){
//             int buy = -prices[ind] + solve(ind+1,0,capacity,prices,dp);
//             int notbuy = 0 + solve(ind+1,1,capacity,prices,dp);
//             profit = max(buy,notbuy);
//         }
//         else{
//             int sell = prices[ind] + solve(ind+1,1,capacity-1,prices,dp);
//             int notsell = 0 + solve(ind+1,0,capacity,prices,dp);
//             profit = max(sell,notsell);
//         }
//         return dp[ind][canBuy][capacity] = profit;
//     }
    
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
//         return solve(0,1,2,prices,dp);
//     }
    
    
    
    
    
//     // bottom-up striver
//     // TC: O(n*2*3) and SC: O(n*2*3)
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
//         // BC-1
//         for(int i=0;i<=1;++i){
//             for(int j=0;j<=2;++j){
//                 dp[n][i][j] = 0;
//             }
//         }
//         // BC-2
//         for(int i=0;i<n;++i){
//             for(int j=0;j<=1;++j){
//                 dp[i][j][0] = 0;
//             }
//         }
        
//         for(int i=n-1;i>=0;--i){
//             for(int j=0;j<=1;++j){
//                 for(int k=1;k<=2;++k){  // k(capacity) = 0 -> BC
//                     int profit = 0;
//                     if(j){
//                         int buy = -prices[i] + dp[i+1][0][k];
//                         int notbuy = 0 + dp[i+1][1][k];
//                         profit = max(buy,notbuy);
//                     }
//                     else{
//                         int sell = prices[i] + dp[i+1][1][k-1];
//                         int notsell = 0 + dp[i+1][0][k];
//                         profit = max(sell,notsell);
//                     }
//                     dp[i][j][k] = profit;
//                 }
//             }
//         }
//         return dp[0][1][2];
//     }
    
    
    
    
    
//     // bottom-up + space-optimization striver
//     // TC: O(n*2*3) and SC: O(2*3)
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<int>> next(2,vector<int>(3,0)), curr(2,vector<int>(3,0));
//         // // BC-1
//         // for(int i=0;i<=1;++i){
//         //     for(int j=0;j<=2;++j){
//         //         dp[n][i][j] = 0;
//         //     }
//         // }
//         // // BC-2
//         // for(int i=0;i<n;++i){
//         //     for(int j=0;j<=1;++j){
//         //         dp[i][j][0] = 0;
//         //     }
//         // }
        
//         for(int i=n-1;i>=0;--i){
//             for(int j=0;j<=1;++j){
//                 for(int k=1;k<=2;++k){  // k(capacity) = 0 -> BC
//                     int profit = 0;
//                     if(j){
//                         int buy = -prices[i] + next[0][k];
//                         int notbuy = 0 + next[1][k];
//                         profit = max(buy,notbuy);
//                     }
//                     else{
//                         int sell = prices[i] + next[1][k-1];
//                         int notsell = 0 + next[0][k];
//                         profit = max(sell,notsell);
//                     }
//                     curr[j][k] = profit;
//                 }
//                 next = curr;
//             }
//         }
//         return next[1][2];
//     }
    
    
    
    
    
    
    // method-2 2d DP striver
//     // top-down striver
//     // TC: O(n*4) and SC: O(n*4) + O(n) -> dp array + call stack
//     int solve(int ind,int transactions,vector<int> &prices,vector<vector<int>> &dp){
//         int n = prices.size();
//         if(ind==n || transactions==4)return 0;
//         if(dp[ind][transactions]!=-1)return dp[ind][transactions];
        
//         int profit = 0;
//         if(transactions%2==0){
//             int buy = -prices[ind] + solve(ind+1,transactions+1,prices,dp);
//             int notbuy = 0 + solve(ind+1,transactions,prices,dp);
//             profit = max(buy,notbuy);
//         }
//         else{
//             int sell = prices[ind] + solve(ind+1,transactions+1,prices,dp);
//             int notsell = 0 + solve(ind+1,transactions,prices,dp);
//             profit = max(sell,notsell);
//         }
//         return dp[ind][transactions] = profit;
//     }
    
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<int>> dp(n,vector<int>(4,-1));
//         return solve(0,0,prices,dp);
//     }
    
    
    
    
    
//     // bottom-up striver
//     // TC: O(n*4) and SC: O(n*4)
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         int k = 2;
//         vector<vector<int>> dp(n+1,vector<int>(2*k+1,0));
        
//         for(int ind=n-1;ind>=0;--ind){
//             for(int tranNo=2*k-1;tranNo>=0;--tranNo){
//                 int profit = 0;
//                 if(tranNo%2==0){
//                     int buy = -prices[ind] + dp[ind+1][tranNo+1];
//                     int notbuy = 0 + dp[ind+1][tranNo];
//                     profit = max(buy,notbuy);
//                 }
//                 else{
//                     int sell = prices[ind] + dp[ind+1][tranNo+1];
//                     int notsell = 0 + dp[ind+1][tranNo];
//                     profit = max(sell,notsell);
//                 }
//                 dp[ind][tranNo] = profit;
//             }
//         }
//         return dp[0][0];
//     }
    
    
    
    
    
    // bottom-up + space-optimization striver
    // TC: O(n*4) and SC: O(4)
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int k = 2;
        vector<int> next(2*k+1,0), curr(2*k+1,0);
        
        for(int ind=n-1;ind>=0;--ind){
            for(int tranNo=2*k-1;tranNo>=0;--tranNo){
                int profit = 0;
                if(tranNo%2==0){
                    int buy = -prices[ind] + next[tranNo+1];
                    int notbuy = 0 + next[tranNo];
                    profit = max(buy,notbuy);
                }
                else{
                    int sell = prices[ind] + next[tranNo+1];
                    int notsell = 0 + next[tranNo];
                    profit = max(sell,notsell);
                }
                curr[tranNo] = profit;
            }
            next = curr;
        }
        return next[0];
    }
};