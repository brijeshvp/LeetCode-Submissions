class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        int mx = 1;
        for(int i=1;i<n;++i){
            int len = 1;
            for(int j=i;j<n;++j){
                if(nums[j-1]<nums[j])len++;
                else break;
                mx = max(mx,len);
            }
        }
        return mx;
    }
};