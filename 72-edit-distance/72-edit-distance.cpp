class Solution {
public:
//     // top-down striver
//     int solve(int m,int n,string &a,string &b,vector<vector<int>> &dp){
//         // BC
//         if(m==0)return n;   // insert operations required = length of 2nd string
//         if(n==0)return m;   // delete operations required = length of 1st string
//         if(dp[m][n]!=-1)return dp[m][n];
        
//         if(a[m-1]==b[n-1])return dp[m][n] = 0 + solve(m-1,n-1,a,b,dp);    // no ops needed
//         else{
//             // hypothetical operations
//             int ins = 1 + solve(m,n-1,a,b,dp);     // insert operation
//             int del = 1 + solve(m-1,n,a,b,dp);     // delete operation
//             int rep = 1 + solve(m-1,n-1,a,b,dp);     // replace operation
            
//             return dp[m][n] = min({ins,del,rep});
//         }
//     }
    
//     int minDistance(string word1, string word2) {
//         int m = word1.size(), n = word2.size();
//         vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
//         return solve(m,n,word1,word2,dp);
//     }
    
    
    
    
    
    
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        // BC -> to initialization
        for(int j=0;j<=n;++j)dp[0][j] = j;
        for(int i=0;i<=m;++i)dp[i][0] = i;
        
        for(int i=1;i<=m;++i){
            for(int j=1;j<=n;++j){
                if(word1[i-1]==word2[j-1])dp[i][j] = 0 + dp[i-1][j-1];  // no ops needed
                else{
                    // hypothetical operations
                    int ins = 1 + dp[i][j-1];     // insert operation
                    int del = 1 + dp[i-1][j];     // delete operation
                    int rep = 1 + dp[i-1][j-1];     // replace operation

                    dp[i][j] = min({ins,del,rep});
                }
            }
        }
        return dp[m][n];
    }
};