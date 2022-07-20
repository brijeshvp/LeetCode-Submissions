class Solution {
public:
    // method-1 -> 2D DP
//     // top-down striver
//     // TC: O(n*n) and SC: O(n*n) + O(n) -> dp array + call stack
//     int solve(int ind,int prev,vector<int> &a,vector<vector<int>> &dp){
//         int n = a.size();
//         if(ind==n)return 0;
//         if(dp[ind][prev+1]!=-1)return dp[ind][prev+1];
        
//         int nottake = 0 + solve(ind+1,prev,a,dp);
//         int take = 0;
//         if(prev==-1 || a[ind]>a[prev])take = 1 + solve(ind+1,ind,a,dp);
//         return dp[ind][prev+1] = max(take,nottake);
//     }
    
//     int lengthOfLIS(vector<int>& a) {        
//         int n = a.size();
//         vector<vector<int>> dp(n,vector<int>(n+1,-1));
//         return solve(0,-1,a,dp);
//     }
    
    
    
    // bottom-up striver
    // TC: O(n*n) and SC: O(n*n)
    int lengthOfLIS(vector<int>& a) {        
        int n = a.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
        for(int ind=n-1;ind>=0;--ind){
            for(int prev=n-1;prev>=-1;--prev){
                int nottake = 0 + dp[ind+1][prev+1];    // 2nd parameter -> prev+1 -> since prev can be -1
                int take = 0;
                if(prev==-1 || a[ind]>a[prev])take = 1 + dp[ind+1][ind+1];  // 2nd parameter -> prev+1 -> since prev can be -1
                dp[ind][prev+1] = max(take,nottake);    // 2nd parameter -> prev+1 -> since prev can be -1
            }
        }
        // 2nd parameter -> prev+1 -> since prev can be -1
        // our final ans = dp[0][-1] -> so return dp[0][0] -> since prev = -1 -> shifted to prev = 0
        return dp[0][0];    
    }
};