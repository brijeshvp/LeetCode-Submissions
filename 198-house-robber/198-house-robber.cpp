class Solution {
public:
    // dp ka state = {i,isPrevAdjRobbed}
    // draw rec tree for 2nd test case
    
//     // top-down
//     int solve(int i,vector<int> &a,vector<int> &dp){
//         if(i<0)return 0;
//         if(i==0)return a[i];
//         if(dp[i]!=-1)return dp[i];
        
//         int pick = a[i] + solve(i-2,a,dp);
//         int nonpick = 0 + solve(i-1,a,dp);
        
//         return dp[i] = max(pick,nonpick);
//     }
    
//     int rob(vector<int>& a) {
//         int n = a.size();
//         vector<int> dp(n,-1);
//         return solve(n-1,a,dp);
//     }
    
    
    
    
//     // bottom-up
//     int rob(vector<int>& a) {
//         int n = a.size();
//         vector<int> dp(n,0);
//         dp[0] = a[0];  
        
//         for(int i=1;i<n;++i){
//             int pick = a[i];
//             if(i-2>=0)pick+=dp[i-2];
            
//             int nonpick = 0 + dp[i-1];
            
//             dp[i] = max(pick,nonpick);
//         }
//         return dp[n-1];
//     }
    
    
    // bottom-up + space optimization
    int rob(vector<int>& a) {
        int n = a.size();
        vector<int> dp(n,0);
        int prev1 = a[0];   // initial nonpick wala case
        int prev2 = 0;  // initial pick wala case
        
        for(int i=1;i<n;++i){
            int pick = a[i];
            if(i-2>=0)pick+=prev2;
            
            int nonpick = 0 + prev1;
            
            int curr = max(pick,nonpick);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};