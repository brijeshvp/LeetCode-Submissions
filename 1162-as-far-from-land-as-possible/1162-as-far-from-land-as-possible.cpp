class Solution {
public:
//     // TLE
//     void dfs(int i,int j,vector<vector<int>> &g,int dist=1){
//         int n = g.size();
//         if(i<0 || j<0 || i>=n || j>=n || (g[i][j]!=0 && g[i][j]<=dist))return;
        
//         g[i][j] = dist;
        
//         dfs(i-1,j,g,dist+1);
//         dfs(i+1,j,g,dist+1);
//         dfs(i,j-1,g,dist+1);
//         dfs(i,j+1,g,dist+1);
//     }
    
//     int maxDistance(vector<vector<int>>& g) {
//         int n = g.size();
        
//         for(int i=0;i<n;++i){
//             for(int j=0;j<n;++j){
//                 if(g[i][j]==1){
//                     g[i][j] = 0;
//                     dfs(i,j,g);   
//                 }
//             }
//         }
        
//         int mx = -1;
//         for(int i=0;i<n;++i){
//             for(int j=0;j<n;++j){
//                 if(g[i][j]>1)mx = max(mx,g[i][j]-1);
//             }
//         }
//         return mx;
//     }
    
    
    // level wise bfs
    int maxDistance(vector<vector<int>>& g) {
        int n = g.size();
        queue<pair<int,int>> q;
        
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(g[i][j]==1){
                    q.push({i-1,j});
                    q.push({i+1,j});
                    q.push({i,j-1});
                    q.push({i,j+1});
                }
            }
        }
        
        int dist = 0;
        while(!q.empty()){
            dist++;
    
            int sz = q.size();
            for(int x=0;x<sz;++x){
                auto node = q.front();
                q.pop();
                
                int i = node.first;
                int j = node.second;
                
                // if g[i][j] is already 1, then either it is land or it is updated as dist
                if(i>=0 && j>=0 && i<n && j<n && g[i][j]==0){
                    g[i][j] = dist;
                    
                    q.push({i-1,j});
                    q.push({i+1,j});
                    q.push({i,j-1});
                    q.push({i,j+1});
                }
            }       
        }
        // dist = 0 or dist = 1 -> ans = -1
        // else ans = dist-1
        return dist==1?-1:dist-1;
    }   
};