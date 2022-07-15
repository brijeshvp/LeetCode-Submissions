class Solution {
public:
    bool allvis(vector<vector<int>>& grid){
        int m = grid.size(), n = grid[0].size();
        int ctzeros = 0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]==0)ctzeros++;
            }
        }
        if(ctzeros==0)return true;
        return false;
    }
    
    // -2 in grid means visited
    int solve(int i,int j,int m,int n,vector<vector<int>> &dp,vector<vector<int> > &grid,int length){
        if(i<0 || j<0 || i>=m || j>=n)return 0;
        if(grid[i][j]==-1 || grid[i][j]==-2)return 0;
        if(grid[i][j]==2){
            // cout<<"len "<<length<<endl;
            // cout<<"backtrack"<<endl;
            // if(allvis(grid))return 1;
            if(length==0)return 1;
            return 0;
        }
        // if(dp[i][j]!=-1)return dp[i][j];
        // cout<<"i:"<<i<<" j:"<<j<<" len:"<<length<<endl;
        grid[i][j] = -2;
        
        int ans1 = solve(i+1,j,m,n,dp,grid,length-1);
        int ans2 = solve(i-1,j,m,n,dp,grid,length-1);
        int ans3 = solve(i,j+1,m,n,dp,grid,length-1);
        int ans4 = solve(i,j-1,m,n,dp,grid,length-1);
        
        grid[i][j] = 0;
        // cout<<"backtrack"<<endl;
        return ans1 + ans2 + ans3 + ans4;   
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int starti = 0, startj = 0;
        int obs = 0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]==1){
                    starti = i;
                    startj = j;
                    break;
                }
                if(grid[i][j] == -1)obs++;
            }
        }
        
        return solve(starti,startj,m,n,dp,grid,m*n-obs-1);
    }
};