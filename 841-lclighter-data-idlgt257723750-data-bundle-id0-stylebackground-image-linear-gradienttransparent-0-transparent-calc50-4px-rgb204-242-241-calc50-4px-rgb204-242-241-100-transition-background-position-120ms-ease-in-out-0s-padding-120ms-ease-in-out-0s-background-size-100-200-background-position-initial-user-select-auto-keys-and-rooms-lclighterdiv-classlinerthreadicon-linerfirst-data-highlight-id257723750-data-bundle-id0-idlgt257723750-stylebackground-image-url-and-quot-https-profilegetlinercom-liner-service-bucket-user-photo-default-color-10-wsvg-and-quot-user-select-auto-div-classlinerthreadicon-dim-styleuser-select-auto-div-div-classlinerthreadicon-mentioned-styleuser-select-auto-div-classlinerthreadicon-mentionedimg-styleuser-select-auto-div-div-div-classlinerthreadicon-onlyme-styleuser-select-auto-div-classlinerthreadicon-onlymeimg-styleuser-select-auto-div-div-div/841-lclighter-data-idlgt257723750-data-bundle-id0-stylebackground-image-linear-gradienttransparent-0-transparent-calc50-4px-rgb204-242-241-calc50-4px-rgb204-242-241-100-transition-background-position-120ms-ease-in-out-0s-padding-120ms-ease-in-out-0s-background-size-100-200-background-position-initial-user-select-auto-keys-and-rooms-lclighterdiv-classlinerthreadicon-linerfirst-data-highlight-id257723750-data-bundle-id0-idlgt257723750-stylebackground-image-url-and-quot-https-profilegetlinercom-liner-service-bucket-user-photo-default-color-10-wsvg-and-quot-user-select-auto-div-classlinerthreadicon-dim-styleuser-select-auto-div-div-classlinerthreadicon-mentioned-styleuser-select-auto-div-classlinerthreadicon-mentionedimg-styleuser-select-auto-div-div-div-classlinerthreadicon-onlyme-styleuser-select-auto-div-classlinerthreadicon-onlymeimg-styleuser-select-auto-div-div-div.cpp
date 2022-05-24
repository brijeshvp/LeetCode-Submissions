class Solution {
public:
    // solve function is nothing but dfs
    void solve(int node,vector<vector<int>>&rooms,vector<int>&vis){
        vis[node] = 1;
        
        for(int it : rooms[node]){
            if(!vis[it]){
                solve(it,rooms,vis);
            }
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> vis(rooms.size(),0);
        solve(0,rooms,vis);
        
        for(int i : vis){
            if(i==0)return false;
        }
        return true;
    }
};