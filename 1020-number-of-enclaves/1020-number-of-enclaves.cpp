class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>&g){
        int m = g.size();
        int n = g[0].size();
        
        if(i<0 || j<0 || i>=m || j>=n)return;
        if(g[i][j]==0)return;
        
        g[i][j] = 0;
        
        dfs(i-1,j,g);
        dfs(i+1,j,g);
        dfs(i,j-1,g);
        dfs(i,j+1,g);
    }
    int numEnclaves(vector<vector<int>>& g) {
        int m = g.size();
        int n = g[0].size();
        
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if((i==0 || j==0 || i==m-1 || j==n-1) && g[i][j]==1)dfs(i,j,g);
            }
        }
        
        int enclaves = 0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(g[i][j]==1)enclaves++;
            }
        }
        
        return enclaves;
    }
};