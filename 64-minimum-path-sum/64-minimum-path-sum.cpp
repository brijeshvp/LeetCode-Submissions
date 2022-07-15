class Solution {
public:
    // variation of unique path grid problems(refer dp sheet)
    int solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>> &dp){
        int m = grid.size(), n = grid[0].size();
        if(i>=m || j>=n)return INT_MAX; // this is imp -> return INT_MAX bcoz we want to minimize the sum -> if we return 0, ans will be always 0(when it goes to invalid index)
        if(i==m-1 && j==n-1)return grid[i][j];
        if(dp[i][j]!=-1)return dp[i][j];
        
        int down = solve(i+1,j,grid,dp);
        if(down!=INT_MAX)down+=grid[i][j];
        int right = solve(i,j+1,grid,dp);
        if(right!=INT_MAX)right+=grid[i][j];
        
        return dp[i][j] = min(down,right);    
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(0,0,grid,dp);
    }
};