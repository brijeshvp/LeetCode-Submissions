class Solution {
public:
    int minJumps(vector<int>& a) {
        int n = a.size();
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < n; i++){
            adj[a[i]].push_back(i);    
        }
            
        set<int> vis; 
        vis.insert(0);
        queue<pair<int,int>> q; 
        q.push({0,0});
        
        int steps = 0;
        while (!q.empty()) {
            int sz = q.size();
            while(sz--){
                int ind = q.front().first;
                int dist = q.front().second;
                q.pop();
                
                if (ind == n - 1) return dist; // Reached to last index
                
                vector<int>& next = adj[a[ind]];
                if(ind-1>=0)next.push_back(ind - 1); 
                if(ind+1<n)next.push_back(ind + 1);
                
                for (auto it : next) {
                    if (!vis.count(it)) {
                        vis.insert(it);
                        q.push({it,dist+1});
                    }
                }
                next.clear(); // avoid later lookup adj a[ind]
            }
            steps++;
        }
        return 0;
    }
};