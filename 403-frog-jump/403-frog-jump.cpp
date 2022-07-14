class Solution {
public:
    // i = array index, k = last jump size
    bool solve(int i,int k,unordered_map<int,int> &mp,vector<int> &stones,unordered_map<string,bool> &dp){
        int n = stones.size();  // mp.size() == stones.size() -> since all elts mapped
        // cout<<i<<" "<<k<<endl;
        if(i>=n)return false;
        if(i==n-1)return true;
        string key = to_string(i) + " " + to_string(k);
        if(dp.count(key))return dp[key];
        
        if(k>1 && mp.count(stones[i]+(k-1) ) && solve(mp[stones[i] + (k-1)],k-1,mp,stones,dp) ){
            return dp[key] = true;
        }
        if(mp.count(stones[i]+(k) ) && solve(mp[stones[i] + (k)],k,mp,stones,dp) ){
            return dp[key] = true;
        }
        if(mp.count(stones[i]+(k+1) ) && solve(mp[stones[i] + (k+1)],k+1,mp,stones,dp) ){
            return dp[key] = true;
        }
        return dp[key] = false;
    }
    
    bool canCross(vector<int>& stones) {
        if(stones[1]!=stones[0]+1)return false;   // 1st jump of 1 unit only
        
        int n = stones.size();
        unordered_map<int,int> mp; // {elt,ind}
        unordered_map<string,bool> dp;
        for(int i=0;i<n;++i){
            mp[stones[i]] = i;
        }
        // vector<int> dp(n,-1);
        // jump to 1th index(i=1) by making 1 jump(k=1) initially
        return solve(1,1,mp,stones,dp);
    }
};