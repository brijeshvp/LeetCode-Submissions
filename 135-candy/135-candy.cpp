class Solution {
public:
    int candy(vector<int>& a) {
        int n = a.size();
        
        vector<int> prefCandies(n,1);
        for(int i=1;i<n;++i){
            if(a[i-1]<a[i])prefCandies[i] = prefCandies[i-1]+1;
        }
        
        vector<int> suffCandies(n,1);
        for(int i=n-2;i>=0;--i){
            if(a[i]>a[i+1])suffCandies[i] = suffCandies[i+1]+1;
        }
        
        int mnCandies = 0;
        for(int i=0;i<n;++i){
            mnCandies+= max(prefCandies[i],suffCandies[i]);
        }
        return mnCandies;
    }
};