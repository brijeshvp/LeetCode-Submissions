class Solution {
public:
    // same question as count subsets sum -> with infinite supply of items
    
//     // top-down striver
//     int solve(int ind,int sum,vector<int> &a,vector<vector<int>> &dp){
//         if(ind==0){
//             if(sum%a[0]==0)return 1;
//             else return 0;
//         }
//         if(dp[ind][sum]!=-1)return dp[ind][sum];

//         int nottake = solve(ind-1,sum,a,dp);
//         int take = 0;
//         if(a[ind]<=sum)take = solve(ind,sum-a[ind],a,dp);

//         return dp[ind][sum] = take + nottake;
//     }
 
//     int change(int amount, vector<int>& coins) {
//         int n = coins.size();
//         vector<vector<int>> dp(n,vector<int>(amount+1,-1));
//         return solve(n-1,amount,coins,dp);
//     }
    
    
    
    
    
//     // bottom-up striver
//     int change(int tar, vector<int>& a) {
//          int n = a.size();
//         vector<vector<int>> dp(n+1,vector<int>(tar+1,0));
//         // BC -> initialization
//         for(int i=0;i<=tar;++i){
//             if(i%a[0]==0)dp[0][i] = 1;
//             else dp[0][i] = 0;
//         }
//         for(int i=1;i<n;++i){
//             for(int j=0;j<=tar;++j){
//                 int nottake = dp[i-1][j];
//                 int take = 0;
//                 if(a[i]<=j)take = dp[i][j-a[i]];

//                 dp[i][j] = take + nottake;
//             }
//         }
//         return dp[n-1][tar];
//     }
    
    
    
    
    
    // bottom-up + space optimization striver
    int change(int tar, vector<int>& a) {
        int n = a.size();
        vector<int> prev(tar+1,0), curr(tar+1,0);
        // BC -> initialization
        for(int i=0;i<=tar;++i){
            if(i%a[0]==0)prev[i] = 1;
            else prev[i] = 0;
        }
        
        for(int i=1;i<n;++i){
            for(int j=0;j<=tar;++j){
                int nottake = prev[j];
                int take = 0;
                if(a[i]<=j)take = curr[j-a[i]];

                curr[j] = take + nottake;
            }
            prev = curr;
        }
        return prev[tar];
    }
};