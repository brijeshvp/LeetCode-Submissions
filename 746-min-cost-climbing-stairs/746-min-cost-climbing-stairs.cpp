class Solution {
public:
//     // top-down  TC:- O(N) and SC:- O(N) + O(N) -> dp array + call stack
//     int dp[1001];
//     int solve(int ind,vector<int> &cost){
//         int n = cost.size();
//         if(ind>=n)return 0;
//         if(dp[ind]!=-1)return dp[ind];
        
//         int ans1 = cost[ind] + solve(ind+1,cost);
//         int ans2 = cost[ind] + solve(ind+2,cost);
        
//         return dp[ind] = min(ans1,ans2);
//     }

//     int minCostClimbingStairs(vector<int>& cost) {
//         memset(dp,-1,sizeof(dp));
//         return min(solve(0,cost),solve(1,cost));
//     }
    
//     // bottom-up -> TC:- O(N) and SC:- O(N)
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n = cost.size();
//         vector<int> dp(n+1,-1);
        
//         dp[n-1] = cost[n-1];
//         dp[n-2] = cost[n-2];
        
//         for(int i=n-3;i>=0;--i){
//             dp[i] = cost[i] + min(dp[i+1],dp[i+2]);
//         }
//         return min(dp[0],dp[1]);
//     }
    
    // bottom-up optimized -> TC:- O(N) and SC:- O(1)
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        int dp_n_1 = cost[n-1];
        int dp_n_2 = cost[n-2];
        int dp_n_3;
        
        for(int i=n-3;i>=0;--i){
            dp_n_3 = cost[i] + min(dp_n_2,dp_n_1);
            dp_n_1 = dp_n_2;
            dp_n_2 = dp_n_3;
        }
        return min(dp_n_2,dp_n_1);
    }
};