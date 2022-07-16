class Solution {
public:
    // top-down striver
    bool solve(int ind,int sum,vector<int> &nums,vector<vector<int>> &dp){
        if(sum==0)return true;
        if(ind==0)return sum == nums[0];
        if(dp[ind][sum]!=-1)return dp[ind][sum];
        
        bool nottake = solve(ind-1,sum,nums,dp);
        bool take = false;
        if(nums[ind]<=sum)take = solve(ind-1,sum-nums[ind],nums,dp);
        
        return dp[ind][sum] = take || nottake;
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i : nums)sum+=i;
        
        if(sum%2==1)return false;
        
        vector<vector<int>> dp(nums.size()+1,vector<int>(sum/2+1,-1));
        return solve(nums.size()-1,sum/2,nums,dp);
    }
};