class Solution {
public:
    int maximumUniqueSubarray(vector<int>& a) {
        int n = a.size();
        
        int mx = 0;
        map<int,int> mp;
        for(int i=0,j=0,sum=0;j<n;++j){
            while(mp.find(a[j])!=mp.end()){
                mp.erase(a[i]);
                sum-=a[i];
                i++;
            }
            mp[a[j]]++;
            sum+=a[j];
            mx = max(mx,sum);
        }
        return mx;
    }
};