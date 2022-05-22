class Solution {
public:
    int solve(string &s,int i,int j,vector<vector<int>> &dp){
        if(i>=j)return 1;
        if(dp[i][j]>=0)return dp[i][j];
        if(s[i]!=s[j])return dp[i][j] = 0;
        return dp[i][j] = solve(s,i+1,j-1,dp);
    }
    
    int countSubstrings(string s) {
        int n = s.size();
        int ct = 0;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=0;i<n;++i){
            for(int j=i;j<n;++j){
                ct+= solve(s,i,j,dp);
            }
        }
        return ct;
    }
};