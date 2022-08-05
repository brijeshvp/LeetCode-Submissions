// https://leetcode.com/problems/combination-sum-iv/discuss/111860/Coin-change-AND-this-problem
// https://leetcode.com/problems/combination-sum-iv/discuss/85120/C%2B%2B-template-for-ALL-Combination-Problem-Set
class Solution {
public:
    int count(vector<int> &nums, int target, int pos,vector<int> &dp) {
        if (pos == nums.size() || target <= 0) {
            return (target == 0) ? 1 : 0;
        }

        if (dp[target] != -1) {
            return dp[target];
        }

        int take = count(nums, target - nums[pos], 0, dp);
        int skip = count(nums, target, pos + 1, dp);

        return dp[target] = take + skip;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,-1);
        return count(nums, target, 0, dp);
        // vector<long long> dp(target+1);
        // dp[0] = 1;
        // for (int i = 1; i <= target; i++) {
        //     for (int n : nums) {
        //         if (i >= n) {
        //             dp[i] += dp[i - n];
        //         }
        //     }
        // }
        // return dp[target];
    }
};