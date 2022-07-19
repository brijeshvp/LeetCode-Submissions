class Solution {
public:
    // top-down striver
    bool solve(int m,int n,string &p,string &s,vector<vector<int>> &dp){
        // BC
        if(m==0 && n==0) return true;
        if(m==0 && n>0) return false;
        if(n==0 && m>0){
            for(int sz=1;sz<=m;++sz){
                if(p[sz-1]!='*')return false;
            }
            return true;
        }
        if(dp[m][n]!=-1)return dp[m][n];
        
        if(p[m-1]==s[n-1] || p[m-1]=='?')return dp[m][n] = solve(m-1,n-1,p,s,dp);
        else if(p[m-1]=='*'){
            return dp[m][n] = solve(m-1,n,p,s,dp) || solve(m,n-1,p,s,dp);
        }
        return dp[m][n] = false;
    }
    
    bool isMatch(string s, string p) {
        int m = p.size(), n = s.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return solve(m,n,p,s,dp);
    }
};