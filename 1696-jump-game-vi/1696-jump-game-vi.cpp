class Solution {
public:
//     int solve(int i,vector<int>& a, int k,vector<int> &dp){
//         int n = a.size();
//         if(i>=n)return 0;
//         if(dp[i]!=-1)return dp[i];
        
//         int mx = INT_MIN;
//         for(int j=1;j<=k;++j){
//             if(i+j>=n)break;
//             mx = max(mx,solve(i+j,a,k,dp));
//         }
//         if(mx==INT_MIN)return a[i];
        
//         return dp[i] = a[i] + mx;
//     }
    
//     int maxResult(vector<int>& a, int k) {
//         int n = a.size();
//         vector<int> dp(n,-1);
//         dp[n-1] = a[n-1];
//         return solve(0,a,k,dp);
//     }
    
    int maxResult(vector<int>& a, int k) {
        int n = a.size();
        
        long long curr = 0;
        deque<int> dq;
        for(int i=n-1;i>=0;--i){
            curr = a[i] + (dq.size()==0?0:a[dq.front()]);
            
            while(!dq.empty() && curr>a[dq.back()])dq.pop_back();
            dq.push_back(i);
            
            if(dq.front()>=i+k)dq.pop_front();
            a[i] = curr;
        }
        return curr;
    }
    
};