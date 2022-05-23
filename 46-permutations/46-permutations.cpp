class Solution {
public:
    void solve(vector<int>&a,vector<vector<int>>&ans,vector<int>&perms,vector<int>&hsh){
        if(perms.size() == a.size()){
            ans.push_back(perms);
            return;
        }
        
        for(int i=0;i<a.size();++i){
            if(hsh[i]==1)continue;
            
            perms.push_back(a[i]);
            hsh[i] = 1;
            solve(a,ans,perms,hsh);
            
            perms.pop_back();
            hsh[i] = 0;
        }
    }
    vector<vector<int>> permute(vector<int>& a) {
        vector<vector<int>> ans;
        vector<int> perms;
        vector<int> hsh(a.size()+1,0);
        
        solve(a,ans,perms,hsh);
        
        return ans;
    }
};