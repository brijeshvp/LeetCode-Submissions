class Solution {
public:
//     // top-down striver
//     int solve(int m,int n,string &s,string &t,vector<vector<int>> &dp){
//         if(n==0)return 1;
//         if(m==0 && n!=0)return 0;
//         if(dp[m][n]!=-1)return dp[m][n];
        
//         if(s[m-1]==t[n-1])return dp[m][n] = solve(m-1,n-1,s,t,dp) + solve(m-1,n,s,t,dp);
//         else return dp[m][n] = solve(m-1,n,s,t,dp);
//     }
    
//     int numDistinct(string s, string t) {
//         int m = s.size(), n = t.size();
//         vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
//         return solve(m,n,s,t,dp);
//     }
    
    
    
    
    // bottom-up striver
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        // NOTE:- must take dp matrix in double bcoz of overflow issues in some test cases -> even will not fit in long long
        // smart trick -> calculate in double and return ans at last in int
        vector<vector<double>> dp(m+1,vector<double>(n+1,0));
        // BC -> initialization
        for(int i=0;i<=m;++i)dp[i][0] = 1;
        // omit j = 0 in below loop since for every j = 0 -> dp[i][j] = 1(above loop)
        for(int j=1;j<=n;++j)dp[0][j] = 0;
        
        for(int i=1;i<=m;++i){
            for(int j=1;j<=n;++j){
                if(s[i-1]==t[j-1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        return (int)dp[m][n];
    }
};