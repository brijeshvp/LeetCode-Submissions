class Solution {
public:
    void solve(int node,vector<vector<int>> &g,vector<vector<int>>&ans,vector<int>&currPath){
        currPath.push_back(node);
        if(node==g.size()-1){
            ans.push_back(currPath);
            return;
        }       
        
        for(int it : g[node]){
            solve(it,g,ans,currPath);
            currPath.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
        vector<vector<int>> ans;
        vector<int> currPath;
        solve(0,g,ans,currPath);
        return ans;
    }
};