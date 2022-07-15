class Solution {
public:
    // -2 in grid means visited
    int solve(int i,int j,vector<vector<int> > &grid,int length){
        int m = grid.size(), n = grid[0].size();
        if(i<0 || j<0 || i>=m || j>=n)return 0;
        if(grid[i][j]==-1 || grid[i][j]==-2)return 0;
        if(grid[i][j]==2){
            // cout<<"len "<<length<<endl;
            // cout<<"backtrack"<<endl;
            if(length==0)return 1;
            return 0;
        }
        // cout<<"i:"<<i<<" j:"<<j<<" len:"<<length<<endl;
        grid[i][j] = -2;
        
        int ans1 = solve(i+1,j,grid,length-1);
        int ans2 = solve(i-1,j,grid,length-1);
        int ans3 = solve(i,j+1,grid,length-1);
        int ans4 = solve(i,j-1,grid,length-1);
        
        grid[i][j] = 0;
        // cout<<"backtrack"<<endl;
        return ans1 + ans2 + ans3 + ans4;   
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
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
        
        return solve(starti,startj,grid,m*n-obs-1);
    }
};