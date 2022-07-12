class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n = a.size();
        
        vector<int> LIS(n+1,1);
        // LIS[0] = 1;
        
        for(int i=1;i<n;++i){
            for(int j=0;j<i;++j){
                if(a[j]<a[i] && LIS[i]<1+LIS[j])LIS[i] = 1 + LIS[j];
            }
        }
        
        int mx = 0;
        for(int i:LIS)mx = max(mx,i);
        return mx;
    }
};