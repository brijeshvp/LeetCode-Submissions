class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        vector<int> indeg(n,0);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            indeg[it[1]]++;
        }
        
        vector<int> nodes;
        for(int i=0;i<n;++i){
            if(indeg[i]==0){
                nodes.push_back(i);
            }
        }
        
        return nodes;
    }
};