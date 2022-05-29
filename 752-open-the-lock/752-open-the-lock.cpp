class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        string src = "0000";
        unordered_set<string> deads(deadends.begin(),deadends.end()), vis;
        
        if(deads.count(src))return -1;
        
        queue<string> q;
        q.push(src);
        int dist = 0;
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                string it = q.front();
                q.pop();
                
                if(it==target)return dist;
                for(int i=0;i<it.size();++i){
                    char tmp = it[i];
                    
                    // forward transition
                    if(it[i]=='9')it[i] = '0';
                    else it[i]++;
                    
                    if(!deads.count(it) && !vis.count(it)){
                        q.push(it);
                        vis.insert(it);
                    }
                    
                    it[i] = tmp;    // reset it[i] back to original state
                    
                    // backward transition
                    if(it[i]=='0')it[i] = '9';
                    else it[i]--;
                    
                    if(!deads.count(it) && !vis.count(it)){
                        q.push(it);
                        vis.insert(it);
                    }
                    
                    it[i] = tmp;    // reset it[i] back to original state
                } 
            }
            dist++;
        }
        return -1;
    }
};