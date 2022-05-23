class Solution {
public:
    int nearestExit(vector<vector<char>>& g, vector<int>& e) {
        int m = g.size();
        int n = g[0].size();
        
        queue<pair<int,int>> q;
        g[e[0]][e[1]] = '0';
        q.push({e[0]+1,e[1]});
        q.push({e[0]-1,e[1]});
        q.push({e[0],e[1]+1});
        q.push({e[0],e[1]-1});
        
        
        vector<vector<int>> temp(m,vector<int>(n,-1));
        int dist = 1;
        while(!q.empty()){
            int sz = q.size();
            for(int ind=0;ind<sz;++ind){
                auto it = q.front();
                q.pop();
                
                int i = it.first;
                int j = it.second;
                
                if(i<0 || j<0 || i>=m || j>=n || g[i][j]!='.')continue;
                
                temp[i][j] = dist;
                g[i][j] = '+';
                q.push({i+1,j});
                q.push({i-1,j});
                q.push({i,j+1});
                q.push({i,j-1});
            }
            dist++;
        }
        
        int ans = INT_MAX;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if((i==0 || i==m-1 || j==0 || j==n-1) && temp[i][j]!=-1){
                    ans = min(ans,temp[i][j]);
                }
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};