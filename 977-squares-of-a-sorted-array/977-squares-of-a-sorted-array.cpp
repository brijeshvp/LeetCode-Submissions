class Solution {
public:
    //     // method-1:- squaring each elt and sorting the squared array
//     // TC:- O(NlogN) -> since sorting required and SC:- O(N)
//     vector<int> sortedSquares(vector<int>& a) {
//         vector<int> sq;
//         int n = a.size();
        
//         for(int i=0;i<n;++i){
//             sq.push_back(a[i]*a[i]);
//         }
        
//         sort(sq.begin(),sq.end());
//         return sq;
//     }
    
    
    
    
    
    
//     // method-2:- TC: O(N) and SC: O(N)
//     vector<int> sortedSquares(vector<int>& a) {
//         vector<int> sq;
//         int n = a.size();
        
//         int lo,hi=n;
//         for(int i=0;i<n;++i){
//             if(a[i]>=0){
//                 hi = i;
//                 break;
//             }
//         }
        
//         lo = hi-1;
//         while(lo>=0 && hi<n){
//             if(abs(a[lo])==a[hi]){
//                 sq.push_back(a[hi]*a[hi]);
//                 sq.push_back(a[hi]*a[hi]);
//                 lo--;
//                 hi++;
//             }
//             else if(abs(a[lo])<a[hi]){
//                 sq.push_back(a[lo]*a[lo]);
//                 lo--;
//             }
//             else if(abs(a[lo])>a[hi]){
//                 sq.push_back(a[hi]*a[hi]);
//                 hi++;
//             }
//         }
        
//         while(lo>=0){
//             sq.push_back(a[lo]*a[lo]);
//             lo--;
//         }
        
//         while(hi<n){
//             sq.push_back(a[hi]*a[hi]);
//             hi++;
//         }
//         return sq;
//     }
    
    
    
    vector<int> sortedSquares(vector<int>& a) {
        int n = a.size();
        
        for(int i=0;i<n;++i){
            a[i] = a[i]*a[i];
        }
        
        sort(a.begin(),a.end());
        
        return a;
    }
};