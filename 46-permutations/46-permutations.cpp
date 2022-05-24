class Solution {
public:
//     // approach-1: with extra space
//     // TC: O(n!*n) and SC: O(n + n) n for using hash array or map and n for storing current permutation(apart from vector of vector in which we will store all permutations)
//     void solve(vector<int>&a,vector<vector<int>>&ans,vector<int>&perms,vector<int>&hsh){
//         if(perms.size() == a.size()){
//             ans.push_back(perms);
//             return;
//         }
        
//         for(int i=0;i<a.size();++i){
//             if(hsh[i]==1)continue;
            
//             perms.push_back(a[i]);
//             hsh[i] = 1;
//             solve(a,ans,perms,hsh);
            
//             perms.pop_back();
//             hsh[i] = 0;
//         }
//     }
//     vector<vector<int>> permute(vector<int>& a) {
//         vector<vector<int>> ans;
//         vector<int> perms;
//         vector<int> hsh(a.size()+1,0);
        
//         solve(a,ans,perms,hsh);
        
//         return ans;
//     }
    
    
    
    void solve(int ind,vector<int>&a,vector<vector<int>>&ans){
        if(ind==a.size()){
            ans.push_back(a);
            return;
        }    
        
        // try every possible index at this index = ind
        for(int i=ind;i<a.size();++i){
            swap(a[ind],a[i]);
            // then try every possible index at next index and so on...
            solve(ind+1,a,ans);
            swap(a[ind],a[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& a) {
        vector<vector<int>> ans;
        solve(0,a,ans);
        return ans;
    }
};