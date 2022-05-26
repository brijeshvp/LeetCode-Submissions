class Solution {
public:
    int dfs(int node,vector<int> adj[],vector<int>&informTime){
        
        int mx = 0;
        for(int it : adj[node]){
            mx = max(mx,dfs(it,adj,informTime));
        }
        return informTime[node] + mx;
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        // manager is a parent array
        // construct adj list
        vector<int> adj[n];
        for(int i=0;i<n;++i){
            if(manager[i]==-1)continue;
            adj[manager[i]].push_back(i);
        }
        
        return dfs(headID,adj,informTime);
    }
};