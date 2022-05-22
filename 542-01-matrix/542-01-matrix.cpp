class Solution {
public:
    vector<vector<int>> dir = {{1,0},{0,-1},{-1,0},{0,1}};
//     int dfs(int i,int j,vector<vector<int>>&mat,vector<vector<int>>&ans){
//         int m = mat.size();
//         int n = mat[0].size();
//         // if(mat[i][j]==0)return 0;
//         // if(mat[i][j]==1 && ans[i][j]>0)return ans[i][j];
//         if(ans[i][j]!=-1)return ans[i][j];
        
//         int mn = INT_MAX;
//         for(auto it : dir){
//             int x = i + it[0];
//             int y = j + it[1];
//             if(x<0 || y<0 || x>=m || y>=n)continue;
            
//             mn = min(mn,dfs(x,y,mat,ans));    
//         }
//         ans[i][j] = 1+mn;
//         return ans[i][j];
//     }
    
//     vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
//         int m = mat.size();
//         int n = mat[0].size();
        
//         vector<vector<int>> ans(m,vector<int>(n,-1));
        
//         for(int i=0;i<m;++i){
//             for(int j=0;j<n;++j){
//                 if(mat[i][j]==0)ans[i][j] = 0;
//             }
//         }
        
//         for(int i=0;i<m;++i){
//             for(int j=0;j<n;++j){
//                 if(mat[i][j]==1 && ans[i][j]==-1)dfs(i,j,mat,ans);
//             }
//         }
//         return ans;
//     }
    
    
    // bfs from 0 cells
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        queue<pair<int,int>> q;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(mat[i][j]==0)q.push({i,j});
                else if(mat[i][j]==1)mat[i][j]=-1;
            }
        }
        
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
            for(auto it: dir){
                int x = i + it[0];
                int y = j + it[1];
                
                if(x<0 || y<0 || x>=m || y>=n || mat[x][y]!=-1)continue;
                
                // mat[i][j] == -1(previously 1)
                mat[x][y] = mat[i][j] + 1;
                q.push({x,y});
            }
        }
        return mat;
    }
};