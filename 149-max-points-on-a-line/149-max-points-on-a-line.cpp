class Solution {
public:
    bool areTwoPointsSame(vector<int> &p1,vector<int> &p2){
        return (p1[0]==p2[0]) && (p1[1]==p2[1]); 
    }
    
    double slope(vector<int> &p1,vector<int> &p2){
        if(p1[0]==p2[0])return INT_MAX; // x co-ordinates same -> slope = inf
        if(p1[1]==p2[1])return 0;   // y co-ordinates same -> slope = 0
        
        return ((double)p2[1]-p1[1])/((double)p2[0]-p1[0]);
    }
    
    int maxPoints(vector<vector<int>>& p) {
//         int n = p.size();
//         if(n<=2)return n;
        
//         set<pair<int,int>> st;
//         int mx = 1;
//         for(int i=0;i<n && !st.count({p[i][0],p[i][1]});++i){
//             auto it = p[i];
            
//             int same = 0;
//             int localMx = 1;
//             unordered_map<double,int> mp;
            
//             for(int j=i+1;j<n;++j){
//                 if(areTwoPointsSame(it,p[j])){
//                     same++;
//                     continue;
//                 }
                
//                 double slp = slope(it,p[j]);
                
//                 if(!mp.count(slp))mp[slp]+=2;   // to add both ith and jth point
//                 else mp[slp]++;
//                 localMx = max(localMx,mp[slp]);
//             }
            
//             st.insert({it[0],it[1]});
//             mx = max(mx,localMx + same);
//         }
//         return mx;
        
        
        
        
        
        int n = p.size();
        if(n<=2)return n;

        unordered_map<double, int> mp;
        int mx = 1;
        for(int i = 0; i < n; i++){
            int duplicate = 1;
            int vertical = 0;
            for(int j = i+1; j < n; j++){
                if(p[i][0] == p[j][0]){
                    if(p[i][1] == p[j][1]){
                        duplicate++;
                    }
                    else{
                        vertical++;
                    }
                }
                else{
                    vector<int> p1 = {p[i][0],p[i][1]};
                    vector<int> p2 = {p[j][0],p[j][1]};
                    double slp = slope(p1,p2);
                    mp[slp]++;
                }
            }
            auto it = mp.begin();
            while(it != mp.end()){
                int t = it->second;
                if((t + duplicate) > mx){
                    mx = t + duplicate;
                }
                it++;
            }
            if((vertical + duplicate) > mx){
                mx = vertical + duplicate;
            }
            mp.clear(); // this is mandatory(think why!)
        }

        return mx;
    }
};