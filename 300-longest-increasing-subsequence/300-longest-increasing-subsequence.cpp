class Solution {
public:
    // top-down striver
    int solve(int ind,int prev,vector<int> &a,vector<vector<int>> &dp){
        int n = a.size();
        if(ind==n)return 0;
        if(dp[ind][prev+1]!=-1)return dp[ind][prev+1];
        
        int nottake = 0 + solve(ind+1,prev,a,dp);
        int take = 0;
        if(prev==-1 || a[ind]>a[prev])take = 1 + solve(ind+1,ind,a,dp);
        return dp[ind][prev+1] = max(take,nottake);
    }
    
    int lengthOfLIS(vector<int>& a) {
//         int n = a.size();
        
//         vector<int> LIS(n+1,1);
        
//         for(int i=1;i<n;++i){
//             for(int j=0;j<i;++j){
//                 if(a[j]<a[i] && LIS[i]<1+LIS[j])LIS[i] = 1 + LIS[j];
//             }
//         }
        
//         int mx = 0;
//         for(int i:LIS)mx = max(mx,i);
//         return mx;
        
        int n = a.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(0,-1,a,dp);
    }
};