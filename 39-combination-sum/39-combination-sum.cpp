class Solution {
public:
//     void solve(int i,vector<int> &c,int t,vector<vector<int>> &ans,vector<int> &combi){
//         if(t<0)return;
//         if(t==0){
//             ans.push_back(combi);
//             // elts are +ve -> so going ahead will increase the sum -> thus return
//             return;
//         }
//         // if t!=0 but i == n
//         if(i==c.size())return;
        
//         combi.push_back(c[i]);
//         solve(i,c,t-c[i],ans,combi);
//         combi.pop_back();   // backtrack
//         solve(i+1,c,t,ans,combi);
//     }
//     vector<vector<int>> combinationSum(vector<int>& c, int t) {
//         vector<vector<int>> ans;
//         vector<int> combi;
//         solve(0,c,t,ans,combi);
//         return ans;
//     }
    void solve(int ind,vector<int> &currCombination,vector<vector<int>> &allCombinations,vector<int> &a,int target){
    int n = a.size();
    // BCs
    if(target<0)return;
    if(target==0){
        allCombinations.push_back(currCombination);
        return;
    }
    if(ind==n)return;
    
    currCombination.push_back(a[ind]);
    target-=a[ind];
    solve(ind,currCombination,allCombinations,a,target);
    currCombination.pop_back();
    target+=a[ind];
    solve(ind+1,currCombination,allCombinations,a,target);
}

vector<vector<int> > combinationSum(vector<int> &a, int b) {
    // sort + remove duplicates
    set<int> st(a.begin(),a.end());
    a.assign(st.begin(),st.end());
    
    vector<vector<int>> allCombinations;
    vector<int> currCombination;
    solve(0,currCombination,allCombinations,a,b);
    
    sort(allCombinations.begin(),allCombinations.end());
    
    return allCombinations;
}
};