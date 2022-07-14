class Solution {
public:
    // FIBONACCI VARIANCE
    // recurrence relation: f(i) = f(i+1) + f(i+2)
    // #ways to reach top from i = #ways to reach top from i+1 + #ways to reach top from i+2.
    // BC: dp[n] = 1, dp[n-1] = 2
    int climbStairs(int n) {
        // BC
        if(n<=1)return n;
        
        vector<int> dp(n+1,0);
        dp[n] = 1;
        dp[n-1] = 2;
        for(int i=n-2;i>=1;--i){
            dp[i] = dp[i+1] + dp[i+2];
        }
        return dp[1];
    }
};