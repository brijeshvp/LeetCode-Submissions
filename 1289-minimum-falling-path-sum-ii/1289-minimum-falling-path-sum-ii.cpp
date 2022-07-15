class Solution {
public:
    // variable start, variable end question(variation of fixed start, variable end question -> triangle)
    // also extention of medium question min falling path sum 
    int solve(int i,vector<vector<int>>& matrix,vector<vector<int>> &dp,int lastCol){
        int n = matrix.size();
        if(i<0 || i>=n)return INT_MAX;   // return INT_MAX, since want to minimize sum
        
        int mn = INT_MAX,minCol=0;
        for(int col=0;col<n;++col){
            if(col==lastCol)continue;
            if(dp[i][col]!=-1){
                if(dp[i][col] < mn){
                    mn = dp[i][col];
                    minCol = col;
                }
                continue;
            }
            
            int sum = matrix[i][col];
            int ans = solve(i+1,matrix,dp,col);
            if(ans!=INT_MAX)sum+=ans;
            if(sum < mn){
                mn = sum;
                minCol = col;
            }
            dp[i][col] = sum;
        }
        return dp[i][minCol] = mn;
    }
    
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(0,grid,dp,-1);
    }
};