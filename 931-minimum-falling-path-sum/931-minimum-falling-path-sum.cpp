class Solution {
public:
    // variable start, variable end question(variation of fixed start, variable end question -> triangle)
    int solve(int i,int j,vector<vector<int>>& matrix,vector<vector<int>> &dp){
        int n = matrix.size();
        if(i<0 || j<0 || i>=n || j>=n)return INT_MAX;   // return INT_MAX, since want to minimize sum
        if(i==n-1)return matrix[i][j];
        if(dp[i][j]!=-1)return dp[i][j];
        
        // cout<<"i:"<<i<<" j:"<<j<<endl;
        int mn = INT_MAX;
        // for(int j=0;j<n;++j){
            int sum = matrix[i][j];
            int ans1 = solve(i+1,j-1,matrix,dp);
            int ans2 = solve(i+1,j,matrix,dp);
            int ans3 = solve(i+1,j+1,matrix,dp);
            
            int mini = min({ans1,ans2,ans3});
            if(mini!=INT_MAX)sum+=mini;
            
            mn = min(mn,sum);
        // }
        return dp[i][j] = mn;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        int mn = INT_MAX;
        for(int i=0;i<n;++i){
            mn = min(mn,solve(0,i,matrix,dp));
        }
        return mn;
    }
};