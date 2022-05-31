class Solution {
public:
    // just check if the graph is bipartite or not(my notes of striver's graph series)
    bool bfs(int i,vector<int> adj[],vector<int>&color){
        queue<int> q;
        q.push(i);
        color[i] = 1;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto it : adj[node]){
                if(color[it]==-1){
                    color[it] = 1 - color[node];
                    q.push(it);
                }
                else if(color[it]==color[node])return false;
            }
        }
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> adj[n+1];
        for(auto it : dislikes){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> color(n+1,-1);
        
        for(int i=1;i<=n;++i){
            if(color[i]==-1){
                if(!bfs(i,adj,color))return false;
            }
        }
        return true;
    }
};