class Solution {
public:
    void dfs(int i,vector<vector<int>> &adjMat,vector<int>&vis){
        int n = adjMat.size();
        
        // if(i<0 || j<0 || i>=n || j>=n)return;
        // if(adjMat[i][j]!=1)return;
        
        // marking -1 means mark visited(no need to maintain vis array seperately)
        // adjMat[i][j] = -1;
        
        // dfs(i+1,j,adjMat);
        // dfs(i-1,j,adjMat);
        // dfs(i,j+1,adjMat);
        // dfs(i,j-1,adjMat);
        
        vis[i] = 1;
        for(int j=0;j<n;++j){
            if(adjMat[i][j]==1 && !vis[j]){
                dfs(j,adjMat,vis);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& adjMat) {
        int n = adjMat.size();
        
        vector<int> vis(n,0);
        int connectedComponents = 0;
        for(int i=0;i<n;++i){
            // for(int j=0;j<n;++j){
            //     if(adjMat[i][j]==1){
            //         connectedComponents++;
            //         dfs(i,j,adjMat);
            //     }
            // }
            if(!vis[i]){
                dfs(i,adjMat,vis);
                connectedComponents++;  
            }  
        }
        return connectedComponents;
    }
};