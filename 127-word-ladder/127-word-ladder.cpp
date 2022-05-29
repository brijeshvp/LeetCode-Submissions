class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> valids(wordList.begin(),wordList.end()), vis;
        if(!valids.count(endWord))return 0;
        
        queue<string> q;
        q.push(beginWord);
        vis.insert(beginWord);
        int dist = 1;   // start dist with 1 bcoz initial string is one state(since its counted as one word)
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                string it = q.front();
                q.pop();
                
                if(it==endWord)return dist;
                
                for(int i=0;i<it.size();++i){
                    char tmp = it[i];
                    for(char j : string("abcdefghijklmnopqrstuvwxyz")){
                        if(j==tmp)continue;
                        
                        it[i] = j;
                        if(valids.count(it) && !vis.count(it)){
                            q.push(it);
                            vis.insert(it);
                        }
                    }
                    it[i] = tmp;
                }
            }
            dist++;
        }
        return 0;
    }
};