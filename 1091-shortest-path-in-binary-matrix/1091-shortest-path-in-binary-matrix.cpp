class Solution {
public:
    void bfs(int i,int j,vector<vector<int>>&g){
        int n = g.size();
        queue<pair<int,int>> q;
        q.push({i,j});
        
        int dist = 0;
        vector<vector<int>> dir = {{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1}};
        
        while(!q.empty()){
            dist++;
            int sz = q.size();
            while(sz--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                if(x<0 || x>=n || y<0 || y>=n || g[x][y]!=0)continue;
                g[x][y] = dist;
                for(auto it : dir){
                    q.push({x+it[0],y+it[1]});
                }   
            }
        }
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& g) {
        int n = g.size();
        if(g[0][0]==1 || g[n-1][n-1]==1)return -1;
            
        bfs(0,0,g);
        
        return (g[n-1][n-1]>0)?g[n-1][n-1]:-1;
    }
};