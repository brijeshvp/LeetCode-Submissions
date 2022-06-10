class Solution {
public:
    // this is variation of longest substring with k unique chars.
    // Refer here:- https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1/#
    // here k = window size = all unique chars in current window
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i=0,j=0;
        unordered_map<char,int> mp;
        int maxi = 0;
        while(j<n){
            mp[s[j]]++;
            // that means there are repeating chars in current window so slide the window until there are repeating chars in current window
            if(mp.size()<j-i+1){
                while(mp.size()<j-i+1){
                    mp[s[i]]--;
                    
                    if(mp[s[i]]==0)mp.erase(s[i]);
                    i++;
                }
                j++;
            }
            else if(mp.size() == j-i+1){
                maxi = max(maxi,j-i+1);
                j++;
            }
            // this case is not possible bcoz #unique chars in a window can't me more than window size
            // else if(mp.size() > j-i+1){}
        }
        return maxi;
    }
    
};