class Solution {
public:
    void solve(int i,vector<int> &c,int t,vector<vector<int>> &ans,vector<int> &combi){
        if(t<0)return;
        if(t==0){
            ans.push_back(combi);
            // elts are +ve -> so going ahead will increase the sum -> thus return
            return;
        }
        // if t!=0 but i == n
        if(i==c.size())return;
        
        combi.push_back(c[i]);
        solve(i,c,t-c[i],ans,combi);
        combi.pop_back();   // backtrack
        solve(i+1,c,t,ans,combi);
    }
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        vector<vector<int>> ans;
        vector<int> combi;
        solve(0,c,t,ans,combi);
        return ans;
    }
};