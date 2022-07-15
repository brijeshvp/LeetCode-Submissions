class Solution {
public:
    int solve(vector<int> &a,int i,int j,vector<int> &dp){
        int n = a.size();
        if(j<i)return 0;
        if(j==i)return a[j];
        
        if(dp[j]!=-1)return dp[j];
        
        int pick = a[j] + solve(a,i,j-2,dp);
        int nonpick = 0 + solve(a,i,j-1,dp);
        return dp[j] = max(pick,nonpick);
    }
    
    int rob(vector<int>& a) {
        int n = a.size();
        // BC
        if(n==1)return a[0];
        
        vector<int> dp(n,-1);
        int ans1 = solve(a,0,n-2,dp);
        for(int i=0;i<n;++i)dp[i] = -1;
        int ans2 = solve(a,1,n-1,dp);
        return max(ans1,ans2);
    }
};