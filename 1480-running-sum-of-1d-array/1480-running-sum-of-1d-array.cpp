class Solution {
public:
    vector<int> runningSum(vector<int>& a) {
//         // brute: TC: O(N^2) and SC: O(N)
//         int n = a.size();
//         vector<int> prefSum(n,0);
        
//         for(int i=0;i<n;++i){
//             int sum = 0;
//             for(int j=i;j>=0;--j){
//                 sum+= a[j];
//             }
//             prefSum[i] = sum;
//         }
//         return prefSum;
        
        
        
        
//         // intermediate TC: O(N) and SC: O(N)
//         int n = a.size();
//         vector<int> prefixSum(n,0);
        
//         prefixSum[0] = a[0];
//         for(int i=1;i<n;++i){
//             prefixSum[i] = prefixSum[i-1] + a[i];
//         }
        
//         return prefixSum;
        
        
        // optimal: TC: O(N) and SC: O(1)
        int n = a.size();
        for(int i=1;i<n;++i){
            a[i]+= a[i-1];
        }
        return a;
    }
};