// class Solution {
// public:
// //     // this approach will give TLE
// //     int numMatchingSubseq(string s, vector<string>& words) {
// //         int n = words.size();
        
// //         int ct = 0;
// //         for(auto &it : words){
// //             int i = 0, j = 0;
// //             while(i<s.size() && j<it.size()){
// //                 if(s[i]==it[j]){
// //                     i++;
// //                     j++;
// //                 }
// //                 else{
// //                     i++;
// //                 }
// //             }
            
// //             if(j==it.size())ct++;
// //         }
// //         return ct;
// //     }
    
    
// //     // optimization
// //     // this approach will give TLE
// //     int numMatchingSubseq(string s, vector<string>& words) {
// //         int n = words.size();
        
// //         // we store words in map bcoz if we do calculations for one word -> than add count of all occurences of same word in words array to avoid re-calculations
// //         unordered_map<string,int> mp;
// //         for(auto &it : words)mp[it]++;
        
// //         int ct = 0;
// //         for(auto &it : words){
// //             if(mp[it]==0)continue;  // check if its calculation has been done previously -> skip calculating again
            
// //             int i = 0, j = 0;
// //             while(i<s.size() && j<it.size()){
// //                 if(s[i]==it[j]){
// //                     i++;
// //                     j++;
// //                 }
// //                 else{
// //                     i++;
// //                 }
// //             }
            
// //             if(j==it.size()){
// //                 ct+=mp[it]; // count all occurences of it and to avoid counting again, reset its freq in map so that next time if same word occurs -> we donot recalculate it
// //                 mp[it] = 0;
// //             }
// //         }
// //         return ct;
// //     }
// };






class Solution {
    int isSubSeq(string& a, string b) {
        
        int i = 0, j = 0;
        int m = a.length(), n = b.length();
        
        while (i < m && j < n) {
            if (a[i] == b[j]) {
                i++; j++;
            } else {
                i++;
            }
        }
        
        return (j == n);
    }
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        
        int c = 0;
        unordered_map<string, int>mp;
        for (int i = 0; i < words.size(); i++)
            mp[words[i]]++;
            
        for (auto it = mp.begin(); it != mp.end(); it++) {
            if (isSubSeq(S, it->first))
                c += it->second;
        }
        
        return c;
    }
};