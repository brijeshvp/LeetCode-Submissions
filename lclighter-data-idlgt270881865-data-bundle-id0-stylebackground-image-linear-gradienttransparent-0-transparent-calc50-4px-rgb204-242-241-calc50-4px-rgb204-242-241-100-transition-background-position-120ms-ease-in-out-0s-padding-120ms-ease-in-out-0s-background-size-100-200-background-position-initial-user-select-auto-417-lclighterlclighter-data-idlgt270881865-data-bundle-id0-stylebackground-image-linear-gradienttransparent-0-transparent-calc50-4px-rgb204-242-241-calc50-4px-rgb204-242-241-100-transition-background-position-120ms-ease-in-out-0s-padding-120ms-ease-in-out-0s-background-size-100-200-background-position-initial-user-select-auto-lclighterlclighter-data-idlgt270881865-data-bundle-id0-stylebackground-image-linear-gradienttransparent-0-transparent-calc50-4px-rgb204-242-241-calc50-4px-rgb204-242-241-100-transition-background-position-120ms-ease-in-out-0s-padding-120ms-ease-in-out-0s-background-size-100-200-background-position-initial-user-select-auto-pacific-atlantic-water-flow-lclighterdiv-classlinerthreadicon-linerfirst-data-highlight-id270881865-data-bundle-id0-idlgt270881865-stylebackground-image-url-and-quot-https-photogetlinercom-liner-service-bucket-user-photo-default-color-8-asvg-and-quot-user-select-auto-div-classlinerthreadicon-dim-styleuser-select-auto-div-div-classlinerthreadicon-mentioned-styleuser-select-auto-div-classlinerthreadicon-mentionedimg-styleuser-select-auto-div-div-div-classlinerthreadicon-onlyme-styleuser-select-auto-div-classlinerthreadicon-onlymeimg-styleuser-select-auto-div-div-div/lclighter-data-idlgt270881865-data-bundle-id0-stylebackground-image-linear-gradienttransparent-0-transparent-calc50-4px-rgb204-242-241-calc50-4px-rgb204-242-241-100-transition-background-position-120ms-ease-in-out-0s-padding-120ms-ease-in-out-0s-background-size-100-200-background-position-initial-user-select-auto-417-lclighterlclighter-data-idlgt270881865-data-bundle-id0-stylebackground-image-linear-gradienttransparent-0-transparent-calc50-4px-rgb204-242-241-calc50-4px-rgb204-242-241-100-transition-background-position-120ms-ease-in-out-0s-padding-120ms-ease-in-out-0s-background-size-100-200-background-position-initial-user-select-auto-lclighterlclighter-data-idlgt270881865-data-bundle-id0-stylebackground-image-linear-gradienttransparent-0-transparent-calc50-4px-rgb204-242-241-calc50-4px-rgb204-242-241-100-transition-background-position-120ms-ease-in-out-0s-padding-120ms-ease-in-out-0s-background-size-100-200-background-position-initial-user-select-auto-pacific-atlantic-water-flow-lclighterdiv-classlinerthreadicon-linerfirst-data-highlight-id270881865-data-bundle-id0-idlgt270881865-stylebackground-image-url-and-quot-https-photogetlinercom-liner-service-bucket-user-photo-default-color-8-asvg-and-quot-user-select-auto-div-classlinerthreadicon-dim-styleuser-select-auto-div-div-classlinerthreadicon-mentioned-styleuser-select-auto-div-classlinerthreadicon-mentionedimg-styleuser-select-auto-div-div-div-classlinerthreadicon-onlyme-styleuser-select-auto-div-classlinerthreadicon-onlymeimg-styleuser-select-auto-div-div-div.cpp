class Solution {
public:
//     // flood fill from ocean to all cells
//     bool dfsPacific(int i,int j,vector<vector<int>> &h,vector<vector<int>> &vis,vector<pair<int,int>> &pacific){
//         int m = h.size();
//         int n = h[0].size();
        
//         if(vis[i][j])return false;
//         if(i>=m || j>=n)return false;
//         if(i==0 || j==0){
//             pacific.push_back({i,j});
//             return true;
//         }
//         vis[i][j] = 1;
        
//         bool ans = false;
//         if(h[i-1][j]<=h[i][j])ans|=dfsPacific(i-1,j,h,vis,pacific);
//         if(h[i+1][j]<=h[i][j])ans|=dfsPacific(i+1,j,h,vis,pacific);
//         if(h[i][j-1]<=h[i][j])ans|=dfsPacific(i,j-1,h,vis,pacific);
//         if(h[i][j+1]<=h[i][j])ans|=dfsPacific(i,j+1,h,vis,pacific);
        
//         if(ans){
//             pacific.push_back({i,j});
//         } 
//         return ans;
//     }
    
//     bool dfsAtlantic(int i,int j,vector<vector<int>> &h,vector<vector<int>> &vis,vector<pair<int,int>> &atlantic){
//         int m = h.size();
//         int n = h[0].size();
        
//         if(vis[i][j])return false;
//         if(i<=0 || j<=0)return false;
//         if(i==m-1 || j==n-1){
//             atlantic.push_back({i,j});
//             return true;
//         }
//         vis[i][j] = 1;
        
//         bool ans = false;
//         if(h[i-1][j]<=h[i][j])ans|=dfsAtlantic(i-1,j,h,vis,atlantic);
//         if(h[i+1][j]<=h[i][j])ans|=dfsAtlantic(i+1,j,h,vis,atlantic);
//         if(h[i][j-1]<=h[i][j])ans|=dfsAtlantic(i,j-1,h,vis,atlantic);
//         if(h[i][j+1]<=h[i][j])ans|=dfsAtlantic(i,j+1,h,vis,atlantic);
        
//         if(ans){
//             atlantic.push_back({i,j});
//         }
//         return ans;
//     }
    
    vector<vector<int>> dir = {{1,0},{0,-1},{-1,0},{0,1}};
    void dfs(int i,int j,vector<vector<int>> &h,vector<vector<int>>&vis,int height){
        int m = h.size();
        int n = h[0].size();
        
        if(i<0 || j<0 || i>=m || j>=n)return;
        if(vis[i][j])return;
        if(h[i][j]<height)return;
        
        vis[i][j] = 1;
        
        for(auto it : dir){
            dfs(i+it[0],j+it[1],h,vis,h[i][j]);
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int m = h.size();
        int n = h[0].size();
        
        vector<vector<int>> pac(m+1,vector<int>(n+1,0));
        vector<vector<int>> atl(m+1,vector<int>(n+1,0));
        // vertical border dfs
        for(int i=0;i<m;++i){
            dfs(i,0,h,pac,INT_MIN);
            dfs(i,n-1,h,atl,INT_MIN);
        }
        
        // horizontal border dfs
        for(int j=0;j<n;++j){
            dfs(0,j,h,pac,INT_MIN);
            dfs(m-1,j,h,atl,INT_MIN);
        }
        
        vector<vector<int>> res;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(pac[i][j] && atl[i][j])res.push_back({i,j});
            }
        }
        return res;
    }
};