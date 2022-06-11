class Solution {
public:
//     int minOperations(vector<int>& a, int x) {
//         int n = a.size();
        
//         long long sum = 0;
//         for(int i: a)sum+=i;
        
//         if(sum<x)return -1;
        
//         int target = sum-x;

//         int tmp = 0;
//         int i = 0, j = 0;
//         int mx = INT_MIN;
//         while(j<n){
//             if(tmp==target) {mx = max(mx,j-i+1); j++;}
//             else if(tmp<target){
//                 tmp+= a[j];
//                 j++;
//             }
//             else{
//                 while(tmp>target){
//                     tmp-=a[i];
//                     i++;
//                 }
//                 // j++;
//             }
//         }
        
//         // tmp = 0;
//         // j = n-1, i = n-1;
//         // while(j>=0){
//         //     if(tmp==target){
//         //         ans2 = j+1 + (n-1-(i+1)+1);
//         //         // break;
//         //     }
//         //     else if(tmp<target){
//         //         tmp+= a[j];
//         //         j--;
//         //     }
//         //     else{
//         //         // while(tmp>target){
//         //             tmp-=a[i];
//         //             i--;
//         //         // }
//         //         // j++;
//         //     }
//         // }
//         // int ans = max(ans1,ans2);
//         // if(ans==INT_MAX)return -1;
        
//         return mx==INT_MIN?-1:n-mx;
//     }
    
    
    
    
    int minOperations(vector<int>& nums, int x) {
        int sum = accumulate(begin(nums), end(nums), 0);
        int l = 0, r = 0, res = INT_MAX, sz = nums.size();
        while (l <= r)
            if (sum >= x) {
                if (sum == x)
                    res = min(res, l + sz - r);
                if (r < sz)
                    sum -= nums[r++];
                else
                    break;
            }
            else
                sum += nums[l++];
        return res == INT_MAX ? -1 : res;
    }
};