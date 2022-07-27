class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2,int ind,bool prevSwapped,vector<vector<int>> &dp){
        // BC
        if(ind==nums1.size())return 0;
        if(dp[ind][prevSwapped]!=-1)return dp[ind][prevSwapped];
        
        int prev1 = nums1[ind-1];
        int prev2 = nums2[ind-1];
        
        if(prevSwapped)swap(prev1,prev2);
        
        // no swap
        int noswap = INT_MAX;
        if((prev1 < nums1[ind]) && (prev2 < nums2[ind]))noswap = 0 + solve(nums1,nums2,ind+1,0,dp);
        
        // swap
        int swap = INT_MAX;
        if((prev2 < nums1[ind]) && (prev1 < nums2[ind]))swap = 1 + solve(nums1,nums2,ind+1,1,dp);
        
        return dp[ind][prevSwapped] = min(noswap,swap);
    }
    
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        return solve(nums1,nums2,1,0,dp);
    }
};