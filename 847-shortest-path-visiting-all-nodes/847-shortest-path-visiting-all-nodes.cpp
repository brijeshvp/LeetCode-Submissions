class Solution {
public:
    int setbit(int mask, int i){
        return mask|(1<<i);
    }
    
    int shortestPathLength(vector<vector<int>>& g) {
        map<int,vector<int>> hm;
        int n = g.size();
        
        // Adjency list of graph
        for(int i=0;i<n;i++){
            if(hm.find(i)==hm.end()){
                hm[i] = {};
            }
            
            int m = g[i].size();
            for(int j=0;j<m;j++){
                hm[i].push_back(g[i][j]);
            }      
        }
        
        //dist 2d array
        //row: bitmask -> visited node set bits are 1
        //column: leading node
        
        int row = 1<<n; // 2^n
        int col = n;
        vector<vector<int>> dist(row,vector<int>(col,-1));
        
        queue<vector<int>> q;
        for(int i=0;i<n;i++){    
            int lead = i;
            int mask = setbit(0,i);
            
            q.push({lead,mask});
            dist[mask][lead] = 0;
        }
        
        
        // Applying simulatneous BFS
        while(q.size()>0){   
            int sz = q.size();
            for(int i=0;i<sz;++i){
                auto it = q.front();
                q.pop();
                
                int lead = it[0];
                int mask = it[1];
                
                if(mask == row-1){   //all nodes visited
                    return dist[mask][lead];
                }
                
                // iterate over neighbours of lead
                if(hm.find(lead)!=hm.end()){
                    
                    for(int child: hm[lead]){
                        int newlead = child;
                        int newmask = setbit(mask, newlead);

                        // avoid cycle: intelligent bfs : checking if this set is already visited 
                        // set : lead, mask(visited nodes)
                        if(dist[newmask][newlead]!=-1){
                            continue;
                        }

                        dist[newmask][newlead] = dist[mask][lead]+1;
                        q.push({newlead,newmask});
                    }
                }   
            } 
        }
        return 1221; //magic - LOL  -> will never reach here!
    }
};