class Solution {
public:
    int m,n;
    void dfs(int i,int j,vector<vector<char>>&g){
        if(i<0 || j<0 || i>=m || j>=n)return;
        if(g[i][j]=='0')return;
        
        g[i][j] = '0';
        
        dfs(i,j+1,g);    
        dfs(i,j-1,g);    
        dfs(i+1,j,g);    
        dfs(i-1,j,g);    
    }
    
    int numIslands(vector<vector<char>>& g) {
        m = g.size();
        n = g[0].size();
        
        int ct=0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(g[i][j]=='1'){
                    dfs(i,j,g);
                    ct++;
                }
            }
        }
        return ct;
    }
};