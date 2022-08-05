// https://leetcode.com/problems/combination-sum-iv/discuss/111860/Coin-change-AND-this-problem
// https://leetcode.com/problems/combination-sum-iv/discuss/85120/C%2B%2B-template-for-ALL-Combination-Problem-Set
class Solution {
public:
    int solve(int i,vector<int> &nums, int target,vector<int> &dp) {
        int n = nums.size();
        if(target==0)return 1;
        if(target<0 || i>=n)return 0;

        if (dp[target] != -1) return dp[target];

        int take = solve(0,nums, target - nums[i], dp);
        int nontake = solve(i+1,nums, target, dp);

        return dp[target] = take + nontake;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,-1);
        return solve(0,nums,target,dp);
    }
};