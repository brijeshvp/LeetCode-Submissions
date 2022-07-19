class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        
        vector<int> prefMin(n,0);
        prefMin[0] = p[0];
        
        int mx = 0;
        for(int i=1;i<n;++i){
            prefMin[i] = min(prefMin[i-1],p[i]);
            mx = max(mx,p[i]-prefMin[i]);
        }
        
        // int mx = 0;
        // for(int i=0;i<n;++i){
        //     mx = max(mx,p[i]-prefMin[i]);
        // }
        
        return mx;
        
        
//         int n = p.size();
        
//         int prefMin = INT_MAX;
//         int mx = 0;
//         for(int i=0;i<n;++i){
//             prefMin = min(prefMin,p[i]);
//             mx = max(mx,p[i]-prefMin);
//         }
        
//         return mx;
    }
};