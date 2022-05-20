class Solution {
public:
    // regular dfs template
    void dfs(int i,int j,vector<vector<int>>&g1,vector<vector<int>>&g2,bool &ans){
        int m = g1.size();
        int n = g1[0].size();
        
        if(i<0 || j<0 || i>=m || j>=n)return;
        if(g2[i][j]==0)return;
        g2[i][j] = 0;
        
        if(g1[i][j]==0)ans = false; // extra part
        
        dfs(i-1,j,g1,g2,ans);
        dfs(i+1,j,g1,g2,ans);
        dfs(i,j-1,g1,g2,ans);
        dfs(i,j+1,g1,g2,ans);
    }
    
    int countSubIslands(vector<vector<int>>& g1, vector<vector<int>>& g2) {
        int m = g1.size();
        int n = g1[0].size();
        
        int sub_islands = 0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(g2[i][j]==1){
                    bool ans = true;
                    dfs(i,j,g1,g2,ans);
                    if(ans)sub_islands++;
                }
            }
        }
        return sub_islands;
    }
};