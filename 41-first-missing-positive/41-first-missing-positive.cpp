class Solution {
public:
    int firstMissingPositive(vector<int>& a) {
        int n = a.size();
        
        for(int i=0;i<n;++i){
            if(a[i]<0)a[i] = 0;
        }
        
        for(int i=0;i<n;++i){
            int tmp = abs(a[i]);
            if(1<=tmp && tmp<=n){
                if(a[tmp-1]>0)a[tmp-1]*=-1;
                else if(a[tmp-1]==0)a[tmp-1]=(-1*(n+1));
            }
        }
        
        for(int i=1;i<=n;++i){
            if(a[i-1]>=0)return i;
        }
        return n+1;
    }
};