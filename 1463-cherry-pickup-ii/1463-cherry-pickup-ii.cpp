class Solution {
public:
    // fixed starting point, variable ending point variation
    // extension of cherry pickup-1 question
    // 3d dp + parallel dfs question
    // dfs individually will not work -> since will have to track common cells by both robots(since any one robot can pick cherries from common cell) -> (complex)
    
//     // top-down
//     // TC: O(m*n*n) and SC: O(m*n*n + n)
//     long long solve(int i,int j1,int j2,vector<vector<int>> &grid,vector<vector<vector<int>>> &dp){
//         int m = grid.size(), n = grid[0].size();
//         if(j1<0 || j2<0 || j1>=n || j2>=n)return INT_MIN;
//         if(i==m-1){
//             if(j1==j2)return grid[i][j1];
//             else return grid[i][j1] + grid[i][j2];
//         }
//         if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
        
//         int mx = 0;
//         // explore all possible paths for robot1 and robot2 simultanously
//         for(int dj1=-1;dj1<=1;++dj1){
//             for(int dj2=-1;dj2<=1;++dj2){
//                 int value = 0;
//                 if(j1==j2)value = grid[i][j1];
//                 else value = grid[i][j1] + grid[i][j2];
                
//                 value+= solve(i+1,j1+dj1,j2+dj2,grid,dp);
//                 mx = max(mx,value);
//             }
//         }
//         return dp[i][j1][j2] = mx;
//     }
    
//     int cherryPickup(vector<vector<int>>& grid) {
//         int m = grid.size(), n = grid[0].size();
//         vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(n,-1)));
//         return solve(0,0,n-1,grid,dp);
//     }
    
    
    
    
    
    
//     // bottom-up
//     // TC: O(m*n*n) and SC: O(m*n*n)
//     int cherryPickup(vector<vector<int>>& grid) {
//         int m = grid.size(), n = grid[0].size();
//         vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(n,0)));
        
//         // BC
//         for(int j1=0;j1<n;++j1){
//             for(int j2=0;j2<n;++j2){
//                 if(j1==j2)dp[m-1][j1][j2] = grid[m-1][j1];
//                 else dp[m-1][j1][j2] = grid[m-1][j1] + grid[m-1][j2];
//             }
//         }
        
//         for(int i=m-2;i>=0;--i){
//             for(int j1=0;j1<n;++j1){
//                 for(int j2=0;j2<n;++j2){      
//                     int mx = 0;
//                     for(int dj1=-1;dj1<=1;++dj1){
//                         for(int dj2=-1;dj2<=1;++dj2){
//                             int value = 0;
//                             if(j1==j2)value = grid[i][j1];
//                             else value = grid[i][j1] + grid[i][j2];
//                             if(j1+dj1>=0 && j1+dj1<n && j2+dj2>=0 && j2+dj2<n)
//                                 value+= dp[i+1][j1+dj1][j2+dj2];
//                             else value = -1e8;
//                             mx = max(mx,value);
//                         }
//                     }
//                     dp[i][j1][j2] = mx;
//                 }
//             }
//         }
//         return dp[0][0][n-1];
//     }
    
    
    
    
    
    
    // bottom-up + space optimization
    // TC: O(m*n*n) and SC: O(n*n)
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> next(n,vector<int>(n,0));
        vector<vector<int>> curr(n,vector<int>(n,0));
        
        // BC
        for(int j1=0;j1<n;++j1){
            for(int j2=0;j2<n;++j2){
                if(j1==j2)next[j1][j2] = grid[m-1][j1];
                else next[j1][j2] = grid[m-1][j1] + grid[m-1][j2];
            }
        }
        
        for(int i=m-2;i>=0;--i){
            for(int j1=0;j1<n;++j1){
                for(int j2=0;j2<n;++j2){      
                    int mx = 0;
                    for(int dj1=-1;dj1<=1;++dj1){
                        for(int dj2=-1;dj2<=1;++dj2){
                            int value = 0;
                            if(j1==j2)value = grid[i][j1];
                            else value = grid[i][j1] + grid[i][j2];
                            if(j1+dj1>=0 && j1+dj1<n && j2+dj2>=0 && j2+dj2<n)
                                value+= next[j1+dj1][j2+dj2];
                            else value = -1e8;
                            mx = max(mx,value);
                        }
                    }
                    curr[j1][j2] = mx;
                }
            }
            next = curr;
        }
        return next[0][n-1];
    }
};