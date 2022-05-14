class Solution {
public:
//     int dfs(int i,vector<pair<int,int>> adj[],vector<int> &vis){
//         vis[i] = 1;
        
//         int time = 0;
//         for(auto it : adj[i]){
//             if(!vis[it.first])time+= it.second+ dfs(it.first,adj,vis);
//         }
//         return time;
//     }
    
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        vector<int> vis(n+1,0);
//         int mx = 0;
//         vis[k] = 1;
//         for(auto it: adj[k]){
//             mx = max(mx,it.second + dfs(it.first,adj,vis));
//         }
        
//         bool flag = true;
//         for(int i=1;i<=n;++i){
//             if(!vis[i])flag = false;
//         }
//         if(flag)return mx;
        
//         return -1;
        
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minH;
        vector<int> dist(n+1,INT_MAX);
        
        dist[k] = 0;
        minH.push({0,k});
        
        while(minH.size()>0){
            int prevNode = minH.top().second;
            int prevDist = minH.top().first;
            minH.pop();
            
            for(auto it : adj[prevNode]){
                if(dist[prevNode] + it.second < dist[it.first]){
                    dist[it.first] = dist[prevNode] + it.second;
                    minH.push({dist[it.first],it.first});
                }
            }
        }
        
        bool flag = true;
        int mx = 0;
        for(int i=1;i<=n;++i){
            if(dist[i]==INT_MAX){
                flag = false;
                break;
            }
            mx = max(mx,dist[i]);
        }
        
        if(!flag)return -1;
        
        return mx;
    }
};