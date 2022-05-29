class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        // dict keeps track of all possible valid genes and seen keeps track of already visited genes so that its not repeated
        unordered_set<string> valids(bank.begin(), bank.end()),vis;
        if(!valids.count(end)) return -1; // if dest not found in valid genes not possible to convert it to dest gene
        // start(src) gene is assumed to be valid
        
        queue<string> q;
        q.push(start);
        int dist = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                string t = q.front();
                q.pop();
                if(t==end) return dist;
                
                for(int i=0; i<t.size(); i++) {
                    char tmp = t[i];
                    for(char c:string("ACGT")) {
                        t[i] = c;
                        if(valids.count(t) && !vis.count(t)) {
                            q.push(t);
                            vis.insert(t);
                        }
                    }
                    t[i] = tmp;
                }
            }
            dist++;
        }
        return -1;
        
    }
};