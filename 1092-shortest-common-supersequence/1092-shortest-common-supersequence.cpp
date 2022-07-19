class Solution {
public:
     // top-down
    // TC: O(m*n) and SC: O(m*n + m+n) -> dp array + call stack space
    int solve(int m,int n,string &a,string &b,vector<vector<int>> &dp){
        // BC
        if(m==0 || n==0)return 0;
        if(dp[m][n]!=-1)return dp[m][n];

        if(a[m-1]==b[n-1])return dp[m][n] = 1 + solve(m-1,n-1,a,b,dp);
        else return dp[m][n] = max(solve(m-1,n,a,b,dp),solve(m,n-1,a,b,dp));
    }

    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        solve(m,n,str1,str2,dp);
        
        string ans = "";
        int i = m, j = n;
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                ans.push_back(str1[i-1]);
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                ans.push_back(str1[i-1]);
                i--;
            }
            else{
                ans.push_back(str2[j-1]);
                j--;
            }
        }
        
        while(i>0){
            ans.push_back(str1[i-1]);
            i--;
        }
        
        while(j>0){
            ans.push_back(str2[j-1]);
            j--;
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};