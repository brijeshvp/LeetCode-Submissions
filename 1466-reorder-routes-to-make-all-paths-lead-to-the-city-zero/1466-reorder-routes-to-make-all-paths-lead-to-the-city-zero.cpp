class Solution {
public:
    int dfs(int node,vector<vector<int>> &adj,vector<int>&vis){
        vis[node] = 1;
        
        int ct = 0;
        for(int it : adj[node]){
            if(vis[abs(it)])continue;
            // if node +ve -> edge going away from 0
            if(it>0)ct++;
            ct+= dfs(abs(it),adj,vis);
        }
        return ct;
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        vector<int> vis(n,0);
        // if i to j is edge, then in adj list, store +ve edge from i to j and -ve edge from j to i.
        for(auto it : connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(-it[0]);
        }
        
        // now start dfs from 0 and count edges not coming to 0(going away from 0)
        return dfs(0,adj,vis);
    }
};