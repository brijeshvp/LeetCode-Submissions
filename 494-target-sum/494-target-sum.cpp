class Solution {
public:
    int solve(int ind,int T,vector<int> &nums,vector<vector<int>> &dp){
        if(ind==0){
            if(nums[0]==0 && T==0)return 2;
            if(T==0 || nums[0]==T)return 1;
            return 0;
        }
        if(dp[ind][T]!=-1)return dp[ind][T];
        
        int nottake = 0 + solve(ind-1,T,nums,dp);
        int take = 0;
        if(nums[ind]<=T)take = solve(ind-1,T-nums[ind],nums,dp);
        
        return dp[ind][T] = take + nottake;
    }
    
    // same question as count partition with given difference
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(int i : nums)sum+=i;
        
        // d = difference which is equal to target here
        //      s1 - s2 = d(target)
        //      s1 + s2 = sum
        
        // ->   2s1 = d(target) + sum
        // s1 = (d(target) + sum)/2
        
        // count #subsets with sum = s1
        
        // edge cases
        if((sum+target<0) || (target + sum)%2 == 1)return 0;  // it has to be even
        int T = (target + sum)/2;
        // NOTE: target can be -ve -> T can be -ve -> so make inner vector of max size of target(since -ve dimension vector -> run time error)
        // consider this TC:
        // [100], target = -200
        
        // or else -> write condition -> if sum - target < 0, return 0
        vector<vector<int>> dp(n,vector<int>(T+1,-1));
        return solve(n-1,T,nums,dp);
    }
};