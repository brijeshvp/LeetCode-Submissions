class Solution {
public:
    void solve(int i,vector<int> &curr,vector<vector<int>> &all,int n,int k){
        if(curr.size()==k){
            all.push_back(curr);
            return;
        }
        
        for(int j=i;j<=n;++j){
            curr.push_back(j);
            solve(j+1,curr,all,n,k);
            curr.pop_back();
        }    
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        vector<vector<int>> all;
        solve(1,curr,all,n,k);
        return all;
    }
};