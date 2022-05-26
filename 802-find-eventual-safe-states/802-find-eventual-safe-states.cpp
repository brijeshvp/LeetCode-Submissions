class Solution {
public:
//     // my approach-> TLE -> 103/112 test cases passed
//     bool dfs(int node,vector<vector<int>>&adj,vector<int>&vis){
//         // BC
//         if(adj[node].size()==0)return true;
        
//         vis[node] = 1;
//         for(int it : adj[node]){
//             if(it == node || vis[it])return false;
            
//             if(!dfs(it,adj,vis))return false;
//         }
//         vis[node] = 0;
//         return true;
//     }
    
//     vector<int> eventualSafeNodes(vector<vector<int>>& g) {
//         // g is the adj list given as input
//         vector<int> ans;
//         vector<int> vis(g.size(),0);
        
//         for(int i=0;i<g.size();++i){
//             if(dfs(i,g,vis))ans.push_back(i);
//         }
//         return ans;
//     }
    
    
    
    
    
    
    
    // the given problem can be considered as a cycle detection problem. If none of the paths from the starting node contains a cycle, the starting node can be called a safe vertex. 
    vector<int> eventualSafeNodes(vector<vector<int>>& g) {
        // g is the adj list given as input
        
        int n = g.size();
        vector<bool> safe(n,false);
        vector<unordered_set<int>> graph(n), rgraph(n);
        
        queue<int> q;
        
        for(int i=0;i<n;++i){
            if(g[i].size()==0)q.push(i);
            for(int it : g[i]){
                graph[i].insert(it);
                rgraph[it].insert(i);
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            safe[node] = true;
            
            for(int it : rgraph[node]){
                graph[it].erase(node);
                
                if(graph[it].size()==0)q.push(it);
            }
        }
        
        vector<int> ans;
        for(int i=0;i<n;++i){
            if(safe[i])ans.push_back(i);
        }
        return ans;
    }
};