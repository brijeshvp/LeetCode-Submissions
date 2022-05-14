class Solution {
public:
    vector<vector<int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};
    bool solve(int i,int j, int x,vector<vector<char>> &b,string w,vector<vector<int>> &vis){
        int m = b.size();
        int n = b[0].size();
        if(x==w.size())return true;
        if(i<0 || j<0 || i>=m || j>=n)return false;
        if(vis[i][j])return false;
        if(b[i][j]!=w[x])return false;
        
        vis[i][j] = 1;
        
        bool flag = false;
        for(auto &it : dir){
            flag|= solve(i+it[0],j+it[1],x+1,b,w,vis);
        }
        vis[i][j] = 0;
        return flag;
    }
    
    
    bool exist(vector<vector<char>>& b, string w) {
        int m = b.size();
        int n = b[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        bool flag = false;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(solve(i,j,0,b,w,vis)){
                    return true;
                }       
            }
        }
        return false;
    }
};

/*
    C A A
    A A A
    B C D
*/