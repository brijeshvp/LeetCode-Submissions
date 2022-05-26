class Solution {
public:
//     Time Complexity :- BigO(N*2^N) where N is the length of string s. This is the worst-case time complexity when all the possible substrings are palindrome.

// Space Complexity :- BigO(N) as space will be used to store the recursion stack
    bool isPalindrome(string &s,int i,int j){
        while(i<j){
            if(s[i]!=s[j])return false;
            
            i++;
            j--;
        }
        return true;
    }
    
    void solve(int ind, string &s,vector<vector<string>> &ans,vector<string> &partition){
        int n = s.size();
        // BC
        if(ind == n){
            ans.push_back(partition);
            return;
        }
        
        for(int i=ind;i<n;++i){
            if(isPalindrome(s,ind,i)){
                partition.push_back(s.substr(ind,i-ind+1));
                solve(i+1,s,ans,partition);
                partition.pop_back();
            }    
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans; 
        vector<string> partition;
        
        solve(0,s,ans,partition);
        
        return ans;
    }
};