class Solution {
public:
    int dp[601][101][101];
    Solution(){
        memset(dp,-1,sizeof(dp));
    }
    
    int solve(int i,int m,int n,vector<pair<int,int>> &temp){
        // BC
        if(m<0 || n<0)return INT_MIN;
        // if(dp[m][n]!=-1)return dp[m][n];
        // if(dp[i]!=-1)return dp[i];
        if(dp[i][m][n]!=-1)return dp[i][m][n];
        if(i==temp.size())return 0;
        
        // cout<<m<<" "<<n<<endl;
        int ans1=0;
        if(m>=temp[i].first && n>=temp[i].second)ans1 =  1 + solve(i+1,m-temp[i].first,n-temp[i].second,temp);
        int ans2 =  solve(i+1,m,n,temp);
        
        // cout<<max(ans1,ans2)<<endl;
        return dp[i][m][n] = max(ans1,ans2);
    }
    
    int findMaxForm(vector<string>& s, int m, int n) {
        vector<pair<int,int>> temp;
        for(int i=0;i<s.size();++i){
            string t = s[i];
            int z = 0, o = 0;
            for(auto it : t){
                if(it=='0')z++;
                else o++;
            }
            temp.push_back({z,o});
        }
        // for(int i=0;i<temp.size();++i){
        //     cout<<temp[i].first<<" "<<temp[i].second<<endl;
        // }
        // cout<<endl;
        // vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        // vector<int> dp(s.size()+1,-1);
       
        // memset(dp,-1,sizeof(dp));
        return solve(0,m,n,temp);
    }
};