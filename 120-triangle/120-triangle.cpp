class Solution {
public:
    int solve(vector<vector<int>> &triangle, vector<vector<int>> &dp,int i,int j){
        if(i==triangle.size()-1){
            return dp[i][j] = triangle[i][j];
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        return dp[i][j] = triangle[i][j] + min(solve(triangle,dp,i+1,j),solve(triangle,dp,i+1,j+1));
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size()+1, vector<int>(triangle[triangle.size()-1].size()+1,-1));
        
        return solve(triangle,dp,0,0);
    }
};