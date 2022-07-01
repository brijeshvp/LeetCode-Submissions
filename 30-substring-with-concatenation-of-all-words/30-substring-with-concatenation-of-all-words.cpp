class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> indexes;
        int n = s.size(), num = words.size();
        if (n == 0 || num == 0) return indexes;
        
        unordered_map<string, int> counts;
        for (string word : words) counts[word]++;
        
        int len = words[0].length();
        for (int i = 0; i <= n - num * len; i++) {
            unordered_map<string, int> seen;
            int j = 0;
            for (; j < num; j++) {
                string word = s.substr(i + j * len, len);
                if (counts.find(word) != counts.end()) {
                    seen[word]++;
                    if (seen[word] > counts[word])
                        break;
                }
                else break;
            }
            if (j == num) indexes.push_back(i);
        }
        return indexes;
    }
};