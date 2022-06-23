class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        int n = s.size();
    
        // map<vector<int>,vector<int>> mp;
        map<string,vector<string>> mp;
        for(int i=0;i<n;++i){
            string st = s[i];

            // vector<int> hsh(26,0);
            // for(int j=0;j<st.size();++j){
            //     hsh[st[j]-'0']++;
            // }

            // mp[hsh].push_back(i+1);

            sort(st.begin(),st.end());
            mp[st].push_back(s[i]);
        }

        vector<vector<string>> ans;
        for(auto &it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};