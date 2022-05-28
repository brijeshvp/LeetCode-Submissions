class Solution {
public:
//     int solve(int i,map<int,int>&hsh,int &a,int &b,int &x, int isBackTwice,int &farthest,set<pair<int,int>>&dp){
//         if(i<0)return INT_MAX;
//         if(i>farthest)return INT_MAX;
//         if(hsh.find(i)!=hsh.end())return INT_MAX;
//         if(i==x)return 0;
//         if(dp.find({i,isBackTwice})!=dp.end())return INT_MAX;
        
//         int ans1 = INT_MAX, ans2 = INT_MAX;
//         if(!isBackTwice){
//             ans1 = solve(i-b,hsh,a,b,x,1,farthest,dp);
//             dp.insert({i-b,1});
//             if(ans1!=INT_MAX)ans1+=1;
//         }
//         ans2 = solve(i+a,hsh,a,b,x,0,farthest,dp);
//         dp.insert({i+a,0});
//         if(ans2!=INT_MAX)ans2+=1; 
        
//         dp.insert({i,isBackTwice});
//         return min(ans1,ans2);
//     }
    
//     int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
//         int n = forbidden.size();
        
//         map<int,int> hsh;
//         for(int i=0;i<n;++i){
//             hsh[forbidden[i]] = 1;
//         }
        
//         int farthest = x + max(a,b);
//         set<pair<int,int>> dp;
//         int ans = solve(0,hsh,a,b,x,0,farthest,dp);
//         return (ans==INT_MAX)?-1:ans;
//     }
    
    
    
    
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        int n = forbidden.size();
        map<int,int> hsh;
        for(int i=0;i<n;++i){
            hsh[forbidden[i]] = 1;
        }
        // {i,isBackTwice}
        queue<pair<int,int>> q;
        q.push({0,0});
        set<pair<int,int>> vis;
        int dist = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto it = q.front();
                q.pop();
                
                int i = it.first;
                int isBackTwice = it.second;
                
                if(i==x)return dist;
                
                // jump forward
                int next_pos = i + a;
                if(hsh.find(next_pos)==hsh.end() && vis.find({next_pos,0})==vis.end() && next_pos<10000){
                    q.push({next_pos,0});
                    vis.insert({next_pos,0});
                }
                
                // jump backward
                next_pos = i - b;
                if( isBackTwice==0 && hsh.find(next_pos)==hsh.end() && vis.find({next_pos,1})==vis.end() && next_pos>=0){
                    q.push({next_pos,1});
                    vis.insert({next_pos,1});
                }
            }
            dist++;
        }
        return -1;
    }
};