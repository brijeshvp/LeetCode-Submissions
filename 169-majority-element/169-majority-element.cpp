class Solution {
public:
    // brute: for each elt, iterate in whole array to count number of times it occurs, if ct>n/2 return that elt
    // TC: O(N^2) and SC: O(1)

    
    
//     // intermidiate: TC: O(N) and SC: O(N)
//     int majorityElement(vector<int>& a) {
//         int n = a.size();
        
//         map<int,int> mp;
//         for(int i=0;i<n;++i){
//             mp[a[i]]++;
//             if(mp[a[i]]>n/2)return a[i];
//         }
//         return -1;  // if no majority elt 
//     }
    
    
    
    
    
    // optimal: TC: O(N) and SC: O(1)
    int majorityElement(vector<int>& a) {
//         int n = a.size();
        
//         int m = a[0];
//         int ct = 1;
//         for(int i=1;i<n;++i){
//             if(a[i]==m)ct++;
//             else ct--;
            
//             if(ct==0){
//                 m = a[i];
//                 ct++;
//             }
//         }
        
//         return m;
        
        int n = a.size();
        int votes = 0;
        int candidate = -1;
        for(int i=0;i<n;++i){
            if(votes==0){
                candidate = a[i];
            }
            
            if(a[i]==candidate)votes++;
            else votes--;
        }
        return candidate;
    }
};