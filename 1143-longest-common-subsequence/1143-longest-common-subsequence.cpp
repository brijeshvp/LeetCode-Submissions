class Solution {
public:
    // recursive TC: O(2^m * 2^n) -> all subseq of string a * all subseq of string b
    
    // top-down striver
    // TC: O(m*n) and SC: O(m*n + m+n) -> dp array + call stack space
    int solve(int m,int n,string &a,string &b,vector<vector<int>> &dp){
        // BC
        if(m==0 || n==0)return 0;
        if(dp[m][n]!=-1)return dp[m][n];
        
        if(a[m-1]==b[n-1])return dp[m][n] = 1 + solve(m-1,n-1,a,b,dp);
        else return dp[m][n] = max(solve(m-1,n,a,b,dp),solve(m,n-1,a,b,dp));
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return solve(m,n,text1,text2,dp);
    }
};