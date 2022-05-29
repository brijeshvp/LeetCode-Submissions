class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> dict(bank.begin(), bank.end());
        if(!dict.count(end)) return -1;
        
        queue<string> q;
        q.push(start);
        int dist = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                string t = q.front();
                q.pop();
                if(t==end) return dist;
                addWord(t, dict, q);
            }
            dist++;
        }
        return -1;
        
    }
    
    void addWord(string word, unordered_set<string>& dict, queue<string>& q) {
        dict.erase(word);
        for(int i=0; i<word.size(); i++) {
            char tmp = word[i];
            for(char c:string("ACGT")) {
                word[i] = c;
                if(dict.count(word)) {
                    q.push(word);
                    dict.erase(word);
                }
            }
            word[i] = tmp;
        }
    }
};