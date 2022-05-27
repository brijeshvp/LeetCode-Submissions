class Solution {
public:
    // my approach-> incorrect -> can't handle parallel edges and self loops
//     vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& r, vector<vector<int>>& b) {
//         vector<int> shPaths(n,-1);
//         vector<pair<int,char>> adj[n];
//         for(int i=0;i<r.size();++i){
//             adj[r[i][0]].push_back({r[i][1],'R'});
//         }
//         for(int i=0;i<b.size();++i){
//             adj[b[i][0]].push_back({b[i][1],'B'});
//         }
        
//         vector<int> vis(n,0);
//         queue<pair<int,char>> q;
//         q.push({0,'.'});
//         shPaths[0] = 0;
        
//         while(!q.empty()){
//             int sz = q.size();
//             while(sz--){
//                 auto it = q.front();
//                 q.pop();
                
//                 int i = it.first;
//                 char clr = it.second;
                
//                 for(auto it : adj[i]){
//                     if(shPaths[it.first]==-1 && clr!=it.second){
//                         shPaths[it.first] = shPaths[i] + 1;
//                         q.push({it.first,it.second});
//                     }
//                 }
//             }
//         }
//         return shPaths;
//     }
    
    
    
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red, vector<vector<int>>& blue) {
        // prepare adjacency matrix
        vector<vector<int>> adjMat(n,vector<int>(n,-INT_MAX));
        for(int i=0;i<red.size();++i){
            int x = red[i][0];
            int y = red[i][1];
            
            adjMat[x][y] = 1;   // mark all red edges with 1
        }
        
        for(int i=0;i<blue.size();++i){
            int x = blue[i][0];
            int y = blue[i][1];
            
            if(adjMat[x][y]==1)adjMat[x][y] = 0;    // if same edge color is also red -> mark multiple color edge with 0
            else adjMat[x][y] = -1;   // mark all blue edges with -1
        }
        
        // for a given node there may be 2 incoming edges of different colors
        set<pair<int,int>> vis; // to mark if {node,clr} is already occured or not
        
        vector<int> ans(n,INT_MAX);
        ans[0] = 0;
        
        queue<pair<int,int>> q;
        // 0 node can be considered both red or blue since starting node(no incoming edge)
        q.push({0,1});
        q.push({0,-1});
        
        // bfs size version with dist
        int dist = 1;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto it = q.front();
                q.pop();

                int node = it.first;
                int clr = it.second;

                // iterate all adj nodes
                for(int i=1;i<n;++i){
                    if((adjMat[node][i]==-clr || adjMat[node][i]==0) && vis.find({i,-clr})==vis.end()){
                        vis.insert({i,-clr});
                        q.push({i,-clr});
                        ans[i] = min(ans[i],dist);
                    }
                }
            }
            dist++;
        }
        
        for(int i=0;i<n;++i){
            if(ans[i]==INT_MAX)ans[i] = -1;
        }
        return ans;
    }
};