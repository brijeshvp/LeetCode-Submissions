class Solution {
public:
//     // top-down striver
//     bool solve(int ind,int sum,vector<int> &nums,vector<vector<int>> &dp){
//         if(sum==0)return true;
//         if(ind==0)return sum == nums[0];
//         if(dp[ind][sum]!=-1)return dp[ind][sum];
        
//         bool nottake = solve(ind-1,sum,nums,dp);
//         bool take = false;
//         if(nums[ind]<=sum)take = solve(ind-1,sum-nums[ind],nums,dp);
        
//         return dp[ind][sum] = take || nottake;
//     }
    
//     bool canPartition(vector<int>& nums) {
//         int sum = 0;
//         for(int i : nums)sum+=i;
        
//         if(sum%2==1)return false;
        
//         vector<vector<int>> dp(nums.size()+1,vector<int>(sum/2+1,-1));
//         return solve(nums.size()-1,sum/2,nums,dp);
//     }
    
    
    
    
    
    // bottom-up + space optimization striver
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i : nums)sum+=i;
        
        if(sum%2==1)return false;
        // assume prev is 0th row(n==0)
        vector<bool> prev(sum/2+1,0), curr(sum/2+1,0);
        
        prev[0] = curr[0] = true;
        if(nums[0]<=sum/2)prev[nums[0]] = true;
        
        for(int i=1;i<nums.size();++i){
            for(int j=1;j<=sum/2;++j){
                bool nottake = prev[j];
                bool take = false;
                if(nums[i]<=j)take = prev[j-nums[i]];
                
                curr[j] = take || nottake;
            }
            prev = curr;
        }
        return prev[sum/2];
    }
};