class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;
        if(n<=1)return dp[n];
        dp[2] = 2;
        
        for(int i=3;i<=n;++i){
            int tot = 0;
            for(int j=1;j<=i;++j){
                tot+= (dp[j-1]*dp[i-j]);
            }
            dp[i] = tot;
        }
        return dp[n];
    }
};