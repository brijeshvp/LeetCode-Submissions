class Solution {
public:
   // LIS variation
    bool check(string &a,string &b){
        // if size diff is not 1 then return false -> can't be part of chain
        if(a.size() != b.size() + 1)return false;
        
        // NOTE: a is bigger string and b is smaller string
        int i = 0, j = 0;
        while(i<a.size()){
            if(a[i]==b[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        
        if(i==a.size() && j==b.size())return true;
        return false;
    }
    
    bool static comp(string a,string b){
        return a.size() < b.size();
    }
    
    int longestStrChain(vector<string>& w) {
       int n = w.size();
        sort(w.begin(),w.end(),comp);
        vector<int> dp(n,1);
        
        int mx = 1;
        for(int ind=0;ind<n;++ind){
            for(int prev=0;prev<ind;++prev){
                if(check(w[ind],w[prev]) && dp[ind]<1+dp[prev]){
                    dp[ind] = 1 + dp[prev];
                }
            }
            if(dp[ind]>mx){
                mx = dp[ind];
            }
        }
        
        return mx;
    }
};