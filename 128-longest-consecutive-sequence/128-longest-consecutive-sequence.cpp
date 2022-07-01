class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        int n = a.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;++i){
            mp[a[i]]=1;
        }
        
        int mx = 0;
        for(int i=0;i<n;++i){
            if(mp[a[i]]==0)continue;
            
            int x = a[i]-1;
            int ct = 1;
            while(mp.count(x)){
                ct++;
                mp[x] = 0;
                x--;
            }
            x = a[i]+1;
            while(mp.count(x)){
                ct++;
                mp[x] = 0;
                x++;
            }
            
            mx = max(mx,ct);
        }
        return mx;
    }
};