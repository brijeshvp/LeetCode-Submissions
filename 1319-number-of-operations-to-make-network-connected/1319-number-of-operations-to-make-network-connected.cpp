class Solution {
public:
    // using DSU
    int par[100002];
    int rank[100002];
    
    int findPar(int a){
        if(a==par[a])return a;
        
        return par[a] = findPar(par[a]);
    }
    
    void _union(int a,int b){
        a = findPar(a);
        b = findPar(b);
        
        if(a!=b){
            if(rank[a]<rank[b]){
                par[a] = b;
            }
            else if(rank[b]<rank[a]){
                par[b] = a;
            }
            else if(rank[b] == rank[a]){
                par[a] = b;
                rank[b]++;
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& c) {
        int edges = c.size();
        if(edges<n-1)return -1;
        
        // initialize DSU
        for(int i=0;i<n;++i){
            par[i] = i;
            rank[i] = 0;
        }
        
        
        for(int i=0;i<c.size();++i){
            _union(c[i][0],c[i][1]);
        }
        
        // standard method to find number of connected components using DSU
        // pass #nodes -> decrease #nodes by 1 after connecting
        int connectedComponents = 0;
        for(int i=0;i<=1e5;++i){
            if(par[i] == i)connectedComponents++;
        }
        
        return connectedComponents-1;   // number of connected components
    }
    
    
    
    
//     // using dfs
//     void dfs(int vertex,vector<int> adj[],vector<int>&vis){
//         vis[vertex] = 1;
        
//         for(int it : adj[vertex]){
//             if(!vis[it]){
//                 dfs(it,adj,vis);
//             }
//         }
//     }
    
//     int makeConnected(int n, vector<vector<int>>& c) {
//         // c.size() == #edges
//         // if (#edges < n-1) -> can't connect n nodes
//         // for connecting n nodes -> we need minimum of n - 1 edges
//         if(c.size()<n-1)return -1;  // BC
        
//         vector<int> vis(n,0);
//         vector<int> adj[n];
//         for(int i=0;i<c.size();++i){
//             adj[c[i][0]].push_back(c[i][1]);
//             adj[c[i][1]].push_back(c[i][0]);
//         }
        
//         int connectedComponents = 0;
//         for(int i=0;i<n;++i){
//             if(!vis[i]){
//                 dfs(i,adj,vis);
//                 connectedComponents++;
//             }
//         }
        
//         // to connect k components(if graph is disconnected) -> k - 1 edges are required
//         return connectedComponents-1;
//     }
};