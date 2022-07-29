class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int n = words.size();
        
        vector<string> ans;
        for(int i=0;i<n;++i){
            unordered_map<char,char> mp;
            set<char> st;
            string s = words[i];
            int ss = s.size();
            
            bool flag = true;
            for(int j=0;j<ss;++j){
                if(mp.count(s[j])){
                    if(mp[s[j]]!=pattern[j]){flag = false; break;}
                    else continue;
                }
                else if(st.count(pattern[j])){flag = false; break;}
                else{
                    mp[s[j]] = pattern[j];
                    st.insert(pattern[j]);
                }
            }
            if(flag)ans.push_back(s);
        }
        return ans;
    }
};