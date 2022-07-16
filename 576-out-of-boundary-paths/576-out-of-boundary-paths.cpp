class Solution {
public:
    #define MOD 1000000007
    long long solve(int startRow,int startColumn,int maxMove,int m,int n,vector<vector<vector<int>>> &dp){
        if(startRow<0 || startRow>=m || startColumn<0 || startColumn>=n)return 1;
        if(maxMove==0)return 0;
        if(dp[startRow][startColumn][maxMove]!=-1)return dp[startRow][startColumn][maxMove];
        
        long long ans1 = solve(startRow-1,startColumn,maxMove-1,m,n,dp);
        long long ans2 = solve(startRow+1,startColumn,maxMove-1,m,n,dp);
        long long ans3 = solve(startRow,startColumn-1,maxMove-1,m,n,dp);
        long long ans4 = solve(startRow,startColumn+1,maxMove-1,m,n,dp);
        
        return dp[startRow][startColumn][maxMove] = (((ans1 + ans2)%MOD + ans3)%MOD + ans4)%MOD;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        // vector<vector<int>> dp(m,vector<int>(n,-1));
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(maxMove+1,-1)));
        // int dp[m][n][maxMove+1];
        // memset(dp,-1,sizeof(dp));
        return solve(startRow,startColumn,maxMove,m,n,dp);
    }
};