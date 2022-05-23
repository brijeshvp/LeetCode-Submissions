class Solution {
public:
//     // bruteforce -> TLE -> 172/175 test case passed
//     // TC: O(2^n * k * log(set size));  k = average length of combinations
//     void solve(int i,vector<int> &c,int t,set<vector<int>> &st,vector<int> &combi){
//         if(t<0)return;
//         if(t==0){
//             st.insert(combi);
//             // elts are +ve -> so going ahead will increase the sum -> thus return
//             return;
//         }
//         // if t!=0 but i == n
//         if(i==c.size())return;
        
//         combi.push_back(c[i]);
//         solve(i+1,c,t-c[i],st,combi);
//         combi.pop_back();   // backtrack
//         solve(i+1,c,t,st,combi);
//     }
    
//     vector<vector<int>> combinationSum2(vector<int>& c, int t) {
//         set<vector<int>> st;
//         vector<int> combi;
//         sort(c.begin(),c.end());
//         solve(0,c,t,st,combi);
        
//         vector<vector<int>> ans;
//         for(auto &it : st){
//             ans.push_back(it);
//         }
        
//         return ans;
//     }
    
    
    
    
    
    // approach-2 -> TC: O(2^n * k) where k = average length of current combination 
    // SC = O(k * x) where x = #combinations and k = average length of current combination
    // this SC is not call stack space
    void solve(int ind,int t,vector<int> &currCombi,vector<vector<int>> &ans,vector<int>&c){
        if(t==0){
            ans.push_back(currCombi);
            return;
        }
        if(ind==c.size())return;
        
        for(int i=ind;i<c.size();++i){
            if(c[i]>t)break;    // can't include any further elts in our current combination
            if(i>ind && c[i]==c[i-1])continue;  // if current elt is same as previous one -> skip(already considered that case -> avoid duplicate combination)
            
            currCombi.push_back(c[i]);
            solve(i+1,t-c[i],currCombi,ans,c);
            currCombi.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& c, int t) {
        vector<vector<int>> ans;
        vector<int> currCombi;
        sort(c.begin(),c.end());

        solve(0,t,currCombi,ans,c);

        return ans;
    }
};