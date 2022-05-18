class Solution {
public:
    void dfs(int vertex,int parent,vector<int> &vis,vector<vector<int>> &critical,vector<int> adj[],int &timer,vector<int> &tin,vector<int> &low){
        vis[vertex] = 1;
        tin[vertex] = low[vertex] = timer++;
        
        for(auto it: adj[vertex]){
            if(it == parent)continue;
            
            if(!vis[it]){
                dfs(it,vertex,vis,critical,adj,timer,tin,low);
                low[vertex] = min(low[vertex],low[it]);
                if(low[it]>tin[vertex]){
                    vector<int> temp;
                    temp.push_back(vertex);
                    temp.push_back(it);
                    critical.push_back(temp);
                }
            }
            else{
                low[vertex] = min(low[vertex],tin[it]);
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(int i=0;i<connections.size();++i){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        vector<vector<int>> critical;
        vector<int> vis(n,0);
        vector<int> tin(n,-1);
        vector<int> low(n,-1);
        int timer = 0;
        dfs(0,-1,vis,critical,adj,timer,tin,low);
       
        return critical;
    }
};