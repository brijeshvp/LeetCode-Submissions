class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        
        bool dp[n+1][n+1];
        memset(dp,false,sizeof(dp));
        
        int start = 0;
        int best_len = 1;
        
        for(int i=0;i<n+1;++i)dp[i][i]=1;
        for(int i=0;i<n;++i){
            if(s[i]==s[i+1]){
                dp[i][i+1] = true;
                start = i;
                best_len = 2;
            }
        }
        // initialization done ... 
        
        // loop for length
        for(int k=3;k<=n;++k){
            // start of string -> L
            for(int i=0;i<n-k+1;++i){
                int j = i+k-1;  // end of string -> R
                
                if(s[i]==s[j] && dp[i+1][j-1]){
                    dp[i][j] = true;
                    
                    if(k>best_len){
                        best_len = k;
                        start = i;  
                    }
                }
            }
        }
        return s.substr(start,best_len);
    }
};