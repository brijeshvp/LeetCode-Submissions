class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adjMat(n,vector<int>(n,0));
        vector<int> deg(n,0);
        
        for(auto it : roads){
            adjMat[it[0]][it[1]] = 1;
            adjMat[it[1]][it[0]] = 1;
            
            deg[it[0]]++;
            deg[it[1]]++;
        }
        
        int mx = INT_MIN;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(i==j)continue;
                
                int tmp = deg[i] + deg[j];
                if(adjMat[i][j]==1)tmp--;
                mx = max(mx,tmp);
            }
        }
        return mx;
    }
};