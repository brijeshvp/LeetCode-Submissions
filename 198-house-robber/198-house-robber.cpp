class Solution {
public:
    // dp ka state = {i,isPrevAdjRobbed}
    // draw rec tree for 2nd test case
    int solve(int i,vector<int> &a,vector<int> &dp){
        if(i<0)return 0;
        if(i==0)return a[i];
        if(dp[i]!=-1)return dp[i];
        
        int pick = a[i] + solve(i-2,a,dp);
        int nonpick = 0 + solve(i-1,a,dp);
        
        return dp[i] = max(pick,nonpick);
    }
    
    int rob(vector<int>& a) {
        int n = a.size();
        int sum = 0;
        vector<int> dp(n,-1);
        return solve(n-1,a,dp);
    }
};