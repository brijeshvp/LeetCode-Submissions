class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>&g){
        int n = g.size();
        if(i<0 || i>=n || j<0 || j>=n)return;
        if(g[i][j]!=1)return;
        
        g[i][j] = -1;
        
        dfs(i+1,j,g);
        dfs(i-1,j,g);
        dfs(i,j+1,g);
        dfs(i,j-1,g);
    }
    
    int shortestBridge(vector<vector<int>>& g) {
        int n = g.size();
        queue<pair<int,int>> q;
        
        bool flag = false;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(g[i][j]==1 && flag==false){
                    flag = true;
                    dfs(i,j,g);
                }
                if(flag)break;
            }
            if(flag)break;
        }
        
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(g[i][j]==1){
                    q.push({i+1,j});
                    q.push({i-1,j});
                    q.push({i,j+1});
                    q.push({i,j-1});
                }
            }
        }
        
        int dist = 1;
        flag = false;
        int x=-1,y=-1;
        while(!q.empty()){
            int sz = q.size();
            for(int ind=0;ind<sz;++ind){
                auto it = q.front();
                q.pop();
                
                int i = it.first;
                int j = it.second;
                
                if(i<0 || j<0 || i>=n || j>=n || g[i][j]!=0)continue;
                // if(g[i][j]==-1){
                //     flag = true;
                //     x = i;
                //     y = j;
                //     break;
                // }
                
                g[i][j] = dist;
                q.push({i+1,j});
                q.push({i-1,j});
                q.push({i,j+1});
                q.push({i,j-1});
            }
            if(flag)break;
            dist++;
        }
        
        int ans = INT_MAX;
        // if(x+1>=0 && y>=0 && x+1<n && y<n && g[x+1][y]>0)ans = min(ans,g[x+1][y]);
        // if(x-1>=0 && y>=0 && x-1<n && y<n && g[x-1][y]>0)ans = min(ans,g[x-1][y]);
        // if(x>=0 && y+1>=0 && x<n && y+1<n && g[x][y+1]>0)ans = min(ans,g[x][y+1]);
        // if(x>=0 && y-1>=0 && x<n && y-1<n && g[x][y-1]>0)ans = min(ans,g[x][y-1]);
        
        // return ans;
        for(int x=0;x<n;++x){
            for(int y=0;y<n;++y){
                if(g[x][y]==-1){
                    if(x+1>=0 && y>=0 && x+1<n && y<n && g[x+1][y]>0)ans = min(ans,g[x+1][y]);
                    if(x-1>=0 && y>=0 && x-1<n && y<n && g[x-1][y]>0)ans = min(ans,g[x-1][y]);
                    if(x>=0 && y+1>=0 && x<n && y+1<n && g[x][y+1]>0)ans = min(ans,g[x][y+1]);
                    if(x>=0 && y-1>=0 && x<n && y-1<n && g[x][y-1]>0)ans = min(ans,g[x][y-1]);
                }
            }
        }
        return ans;
    }
};