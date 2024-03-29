class Solution {
public:
    // method-1 -> 2D DP
//     // top-down striver
//     // TC: O(n*n) and SC: O(n*n) + O(n) -> dp array + call stack
//     int solve(int ind,int prev,vector<int> &a,vector<vector<int>> &dp){
//         int n = a.size();
//         if(ind==n)return 0;
//         if(dp[ind][prev+1]!=-1)return dp[ind][prev+1];
        
//         int nottake = 0 + solve(ind+1,prev,a,dp);
//         int take = 0;
//         if(prev==-1 || a[ind]>a[prev])take = 1 + solve(ind+1,ind,a,dp);
//         return dp[ind][prev+1] = max(take,nottake);
//     }
    
//     int lengthOfLIS(vector<int>& a) {        
//         int n = a.size();
//         vector<vector<int>> dp(n,vector<int>(n+1,-1));
//         return solve(0,-1,a,dp);
//     }
    
    
    
//     // bottom-up striver
//     // TC: O(n*n) and SC: O(n*n)
//     int lengthOfLIS(vector<int>& a) {        
//         int n = a.size();
//         vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
//         for(int ind=n-1;ind>=0;--ind){
//             for(int prev=n-1;prev>=-1;--prev){
//                 int nottake = 0 + dp[ind+1][prev+1];    // 2nd parameter -> prev+1 -> since prev can be -1
//                 int take = 0;
//                 if(prev==-1 || a[ind]>a[prev])take = 1 + dp[ind+1][ind+1];  // 2nd parameter -> prev+1 -> since prev can be -1
//                 dp[ind][prev+1] = max(take,nottake);    // 2nd parameter -> prev+1 -> since prev can be -1
//             }
//         }
//         // 2nd parameter -> prev+1 -> since prev can be -1
//         // our final ans = dp[0][-1] -> so return dp[0][0] -> since prev = -1 -> shifted to prev = 0
//         return dp[0][0];    
//     }
    
    
    
    
    
    
//     // bottom-up + space-optimization striver
//     // TC: O(n*n) and SC: O(2n)
//     int lengthOfLIS(vector<int>& a) {        
//         int n = a.size();
//         vector<int> next(n+1,0), curr(n+1,0);
        
//         for(int ind=n-1;ind>=0;--ind){
//             for(int prev=n-1;prev>=-1;--prev){
//                 int nottake = 0 + next[prev+1];    // 2nd parameter -> prev+1 -> since prev can be -1
//                 int take = 0;
//                 if(prev==-1 || a[ind]>a[prev])take = 1 + next[ind+1];  // 2nd parameter -> prev+1 -> since prev can be -1
//                 curr[prev+1] = max(take,nottake);    // 2nd parameter -> prev+1 -> since prev can be -1
//             }
//             next = curr;
//         }
//         // 2nd parameter -> prev+1 -> since prev can be -1
//         // our final ans = dp[0][-1] -> so return dp[0][0] -> since prev = -1 -> shifted to prev = 0
//         return next[0];    
//     }
    
    
    
    
    
//     // method-2 striver -> 1D DP
//     // bottom-up striver
//     // TC: O(n*n) and SC: O(n)
//     int lengthOfLIS(vector<int>& a) {        
//         int n = a.size();
        
//         vector<int> dp(n,1);
//         dp[0] = 1;
        
//         int mx = 1;
//         for(int ind=1;ind<n;++ind){
//             for(int prev=0;prev<ind;++prev){
//                 if(a[prev]<a[ind] && dp[ind]<1+dp[prev]) dp[ind] = 1 + dp[prev];
//             }
//             mx = max(mx,dp[ind]);
//         }
        
//         return mx;
 
//     }
    
    
    
    
    
//     // method-2
//     // bottom-up + store LIS striver
//     // TC: O(n*n + len(LIS)) and SC: O(n)
//     int lengthOfLIS(vector<int>& a) {        
//         int n = a.size();
        
//         vector<int> dp(n,1);
//         vector<int> hsh(n);
        
//         int mx = 1;
//         int lastIndOfLIS = 0;
//         for(int ind=0;ind<n;++ind){
//             hsh[ind] = ind;
//             for(int prev=0;prev<ind;++prev){
//                 if(a[prev]<a[ind] && dp[ind]<1+dp[prev]){
//                     dp[ind] = 1 + dp[prev];
//                     hsh[ind] = prev;
//                 }
//             }
//             if(dp[ind]>mx){
//                 mx = dp[ind];
//                 lastIndOfLIS = ind;
//             }
//         }
        
//         vector<int> LIS;
//         LIS.push_back(a[lastIndOfLIS]);
//         while(lastIndOfLIS != hsh[lastIndOfLIS]){
//             lastIndOfLIS = hsh[lastIndOfLIS];
//             LIS.push_back(a[lastIndOfLIS]);
//         }
        
//         reverse(LIS.begin(),LIS.end());
        
//         // for(int i : LIS)cout<<i<<" ";
//         // cout<<endl;
//         return mx;
 
//     }
    
    
    
    
    // method-3 -> Binary Search approach striver(best approach)
    // TC: O(NlogN) and SC: O(N) 
    // NOTE: this approach will give us the length of LIS and cannot help us to get actual LIS in temp array
    int lengthOfLIS(vector<int>& a) {        
        int n = a.size();
        
        vector<int> temp;
        temp.push_back(a[0]);
        for(int i=1;i<n;++i){
            if(a[i]>temp.back())temp.push_back(a[i]);
            else{
                // dry run test case-2 -> to understand why we have taken lower_bound and not upper_bound
                // bcoz we want to overwrite -> same elt also if available in temp
                int ind = lower_bound(temp.begin(),temp.end(),a[i]) - temp.begin();
                temp[ind] = a[i];
            }
        }
        
        return temp.size();
    }
    
};