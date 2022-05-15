class Solution {
public:
//     int majorityElement(vector<int>& a) {
//         int n = a.size();
        
//         int m;
//         int ct = 0;
//         for(int i=0;i<n;++i){
//             if(ct==0){
//                 m = a[i];
//                 ct++;
//             }
//             else{
//                 if(m==a[i])ct++;
//                 else ct--;
//             }
//         }
        
//         return m;
//     }
    
    
//     // optimal: TC: O(N) and SC: O(1)
//     int majorityElement(vector<int>& a) {
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
//     }
    
    int majorityElement(vector<int>& a) {
        int n = a.size();
        
        map<int,int> mp;
        for(int i=0;i<n;++i){
            mp[a[i]]++;
            if(mp[a[i]]>n/2)return a[i];
        }
        return -1;
        
    }
};