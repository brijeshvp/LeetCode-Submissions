class comp{
public:
    bool operator() (const int& x, const int& y) const {
        return x>y;
    }
};

class Solution {
public:
    int minJumps(vector<int>& a) {
        int n = a.size();
        unordered_map<int,set<int,comp>> adj;
        
        for(int i=0;i<n;++i){
            // adj[a[i]].push_back(i);
            adj[a[i]].insert(i);
        }
        
        set<int> vis;
        queue<pair<int,int>> q;
        q.push({0,0});  // q of {index,dist}
        vis.insert(0);
        while(!q.empty()){
            int ind = q.front().first;
            int dist = q.front().second;
            q.pop();
            if(ind==n-1)return dist;
            
            if(ind-1>=0 && !vis.count(ind-1)){
                vis.insert(ind-1);
                adj[a[ind-1]].erase(ind-1);
                q.push({ind-1,dist+1});
            }
            if(ind+1<n && !vis.count(ind+1)){
                vis.insert(ind+1);
                adj[a[ind+1]].erase(ind+1);
                q.push({ind+1,dist+1});
            }
            for(auto it : adj[a[ind]]){
                if(!vis.count(it)){
                    vis.insert(it);
                    adj[a[ind]].erase(it);
                    q.push({it,dist+1});
                }
            }
        }
        return -1;
    }
};