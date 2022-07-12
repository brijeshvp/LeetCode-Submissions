class Solution {
public:
    int findNumberOfLIS(vector<int>& a) {
        int n = a.size();
        
        vector<int> LIS_len(n,1),LIS_ct(n,1);
        
        for(int i=0;i<n;++i){
            for(int j=0;j<i;++j){
                //If current element is smaller
                if(a[j]>=a[i]) continue;
                
                if(a[j]<a[i] && LIS_len[i]<LIS_len[j]+1){
                    LIS_len[i] = LIS_len[j] + 1;
                    LIS_ct[i] = LIS_ct[j];
                }
                else if(a[j]<a[i] && LIS_len[i]==(LIS_len[j]+1)){
                    LIS_ct[i] = LIS_ct[i] + LIS_ct[j];
                }
            }
        }
        
        int mx = 0;
        for(int i:LIS_len)mx = max(mx,i);
        
        int ct = 0;
        for(int i=0;i<LIS_ct.size();++i){
            if(LIS_len[i]==mx)ct+=LIS_ct[i];
        }
        return ct;
    }
};