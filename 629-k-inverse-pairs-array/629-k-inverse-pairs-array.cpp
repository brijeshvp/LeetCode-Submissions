class Solution {
public:
//     #define MOD 1000000007
    
//     int kInversePairs(int n, int k) {
//         if(n==1 && k==0)return 1;
//         if(n==1 && k>0)return 0;
        
//         vector<vector<int>> dp(n+1,vector<int>(k+1,0));
//         dp[1][0] = 1;
        
//         for(int i=2;i<=n;++i){
//                 int curr = 0;
//                 int prev = (i-1)*(i-2)/2;
//                 while(curr<=(i*(i-1)/2-prev)){ 
//                     for(int j=0;j<=prev;++j){
//                         if(curr+j>k)break;
//                         dp[i][curr+j]= (1LL*dp[i][curr+j] + 1LL*dp[i-1][j])%MOD; 
//                     }
//                     curr++;   
//                 }
//         }
        
//         // for(int i=0;i<=n;++i){
//         //     for(int j=0;j<=k;++j){
//         //         cout<<dp[i][j]<<" ";
//         //     }
//         //     cout<<endl;
//         // }
//         // cout<<endl;
//         return dp[n][k];
//     }
    
    
    
    
    int dp[1001][1001] = { 1 };
    int kInversePairs(int n, int k) {
        if (dp[n][k])
            return dp[n][k];
        for (int N = 1; N <= n; ++N)
            for (int K = 0; K <= k; ++K) {
                dp[N][K] = (dp[N - 1][K] + (K > 0 ? dp[N][K - 1] : 0)) % 1000000007;
                if (K >= N)
                    dp[N][K] = (1000000007 + dp[N][K] - dp[N - 1][K - N]) % 1000000007;
            }
        return dp[n][k];
    }
};