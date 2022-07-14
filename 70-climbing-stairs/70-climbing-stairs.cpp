class Solution {
public:
    // FIBONACCI VARIANCE
    // reverse fibonacci
    // recurrence relation: f(i) = f(i+1) + f(i+2)
    // #ways to reach top from i = #ways to reach top from i+1 + #ways to reach top from i+2.
    // BC: dp[n] = 1, dp[n-1] = 2
    
//     // bottom-up -> TC: O(n) and SC: O(n)
//     int climbStairs(int n) {
//         // BC
//         if(n<=1)return n;
        
//         vector<int> dp(n+1,0);
//         dp[n] = 1;
//         dp[n-1] = 2;
//         for(int i=n-2;i>=1;--i){
//             dp[i] = dp[i+1] + dp[i+2];
//         }
//         return dp[1];
//     }
    
    // space optimized bottom-up -> TC: O(n) and SC: O(1)
    int climbStairs(int n) {
        // BC
        if(n<=1)return n;
        
        int prev2 = 1;
        int prev1 = 2;
        for(int i=n-2;i>=1;--i){
            int curr = prev2 + prev1;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};