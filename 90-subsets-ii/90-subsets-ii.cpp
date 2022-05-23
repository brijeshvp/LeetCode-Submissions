class Solution {
public:
    void solve(int ind,vector<int>&a,vector<vector<int>> &ans,vector<int>&subset){
        ans.push_back(subset);
        
        for(int i=ind;i<a.size();++i){
            if(i>ind && a[i]==a[i-1])continue;
            
            subset.push_back(a[i]);
            solve(i+1,a,ans,subset);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& a) {
        vector<vector<int>> ans;
        vector<int> subset;
        
        sort(a.begin(),a.end());
        solve(0,a,ans,subset);
        
        return ans;
    }
};