class Solution {
public:
    // int minOperations(vector<int>& nums, int x) {
    //     int sum = accumulate(begin(nums), end(nums), 0);
    //     int l = 0, r = 0, res = INT_MAX, sz = nums.size();
    //     while (l <= r)
    //         if (sum >= x) {
    //             if (sum == x)
    //                 res = min(res, l + sz - r);
    //             if (r < sz)
    //                 sum -= nums[r++];
    //             else
    //                 break;
    //         }
    //         else
    //             sum += nums[l++];
    //     return res == INT_MAX ? -1 : res;
    // }
    
    
    
    
    int minOperations(vector<int>& a, int x) {
        int n = a.size();
        long long sum = 0;
        for(int i: a)sum+=i;
        if(sum<x) return -1;
        long long target = sum - x;
        
        int mx = -1;
        long long tmp = 0;
        int i = 0, j = 0;
        for(;j<n;++j){
            tmp+=a[j];
            while(tmp>target && i<=j){
                tmp-=a[i];
                i++;
            }
            if(tmp==target) mx=max(mx, j-i+1);
        }
        return mx==-1?-1:n-mx;
    }
};