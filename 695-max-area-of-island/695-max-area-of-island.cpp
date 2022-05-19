class Solution {
public:
//     int maxi = 0;
//     void dfs(int i,int j,vector<vector<int>>& g,int &ans){
//         if(i<0 || j<0 || i>=g.size() || j>=g[i].size())return;
//         if(g[i][j]==0)return;
        
//         g[i][j] = 0;
        
//         ans++;
//         dfs(i,j+1,g,ans);
//         dfs(i,j-1,g,ans);
//         dfs(i+1,j,g,ans);
//         dfs(i-1,j,g,ans);
//     }
    
//     int maxAreaOfIsland(vector<vector<int>>& g) {
//         int m = g.size();
        
//         for(int i=0;i<m;++i){
//             for(int j=0;j<g[i].size();++j){
//                 if(g[i][j]==1){
//                     int ans = 0;
//                     dfs(i,j,g,ans);
//                     maxi = max(maxi,ans);
//                 }
//             }
//         }
//         return maxi;
//     }
    
    
    
    
    
    
    
    int dfs(int i,int j,vector<vector<int>>& g){
        if(i<0 || j<0 || i>=g.size() || j>=g[i].size())return 0;
        if(g[i][j]==0)return 0;
        
        g[i][j] = 0;
        
        return 1 + dfs(i,j+1,g) + dfs(i,j-1,g) + dfs(i+1,j,g) + dfs(i-1,j,g);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& g) {
        int m = g.size();
        int maxi = 0;
        
        for(int i=0;i<m;++i){
            for(int j=0;j<g[i].size();++j){
                if(g[i][j]==1){
                    maxi = max(maxi,dfs(i,j,g));
                }
            }
        }
        return maxi;
    }
};