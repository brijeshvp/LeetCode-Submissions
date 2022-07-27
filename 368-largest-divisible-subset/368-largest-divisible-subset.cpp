class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        
        sort(nums.begin(),nums.end());
        // now it's just LDS problem(Longest Divisible Subsequence)
        
        int mx = 1;
        int lastIndexOfLDS = 0;
        vector<int> dp(n,1);
        dp[0] = 1;
        vector<int> hash(n);
        hash[0] = 0;
        for(int i=1;i<n;++i){
            hash[i] = i;
            for(int prev_ind = 0;prev_ind<i;++prev_ind){
                if(nums[i]%nums[prev_ind]==0 && dp[i]<1+dp[prev_ind]){
                    dp[i] = 1 + dp[prev_ind];
                    hash[i] = prev_ind;
                }
            }
            if(dp[i]>mx){
                mx = dp[i];
                lastIndexOfLDS = i;
            }
        }
        
        vector<int> lds;
        lds.push_back(nums[lastIndexOfLDS]);
        while(lastIndexOfLDS != hash[lastIndexOfLDS]){
            lastIndexOfLDS = hash[lastIndexOfLDS];
            lds.push_back(nums[lastIndexOfLDS]);
        }
        
        reverse(lds.begin(),lds.end());
        
        return lds;
    }
};