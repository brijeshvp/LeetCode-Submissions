class Solution {
public:
    // recursive TC: O(2^m * 2^n) -> all subseq of string a * all subseq of string b
    
//     // top-down striver
//     // TC: O(m*n) and SC: O(m*n + m+n) -> dp array + call stack space
//     int solve(int m,int n,string &a,string &b,vector<vector<int>> &dp){
//         // BC
//         if(m==0 || n==0)return 0;
//         if(dp[m][n]!=-1)return dp[m][n];
        
//         if(a[m-1]==b[n-1])return dp[m][n] = 1 + solve(m-1,n-1,a,b,dp);
//         else return dp[m][n] = max(solve(m-1,n,a,b,dp),solve(m,n-1,a,b,dp));
//     }
    
//     int longestCommonSubsequence(string text1, string text2) {
//         int m = text1.size(), n = text2.size();
//         vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
//         return solve(m,n,text1,text2,dp);
//     }
    
    
    
//     // bottom-up striver
//     // TC: O(m*n) and SC: O(m*n)
//     int longestCommonSubsequence(string text1, string text2) {
//         int m = text1.size(), n = text2.size();
//         vector<vector<int>> dp(m+1,vector<int>(n+1,0));
//         // BC -> initialization
//         for(int i=0;i<=m;++i)dp[i][0] = 0;
//         for(int i=0;i<=n;++i)dp[0][i] = 0;
        
//         // recursion -> for loops
//         for(int i=1;i<=m;++i){
//             for(int j=1;j<=n;++j){
//                 if(text1[i-1]==text2[j-1])dp[i][j] = 1 + dp[i-1][j-1];
//                 else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
//             }
//         }
//         return dp[m][n];
//     }
    
    
    
    
    // bottom-up + space-optimization striver
    // TC: O(m*n) and SC: O(2n)
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<int> prev(n+1,0),curr(n+1,0);    // size of both arrays should be = row size of 2D dp matrix = n+1
        // BC -> initialization
        // for(int i=0;i<=m;++i)dp[i][0] = 0;
        for(int i=0;i<=n;++i)prev[i] = 0;
        
        // recursion -> for loops
        for(int i=1;i<=m;++i){
            for(int j=1;j<=n;++j){
                if(text1[i-1]==text2[j-1])curr[j] = 1 + prev[j-1];
                else curr[j] = max(prev[j],curr[j-1]);
            }
            prev = curr;
        }
        return prev[n];
    }
};