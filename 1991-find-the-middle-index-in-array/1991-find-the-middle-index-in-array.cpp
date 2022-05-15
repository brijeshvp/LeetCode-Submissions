class Solution {
public:
    int findMiddleIndex(vector<int>& a) {
         // brute: TC: O(N^2) and SC: O(1)
//         int n = a.size();
//         for(int i=0;i<n;++i){
//             int leftSum = 0;
//             for(int j=i-1;j>=0;--j){
//                 leftSum+= a[j];
//             }
            
//             int rightSum = 0;
//             for(int j=i+1;j<n;++j){
//                 rightSum+= a[j];
//             }
            
//             if(leftSum==rightSum)return i;
//         }
//         return -1;
        
        
        
        
        // optimal: TC: O(N) and SC: O(1)
         int sum = 0;
        int n = a.size();
        
        for(int i=0;i<n;++i){
            sum+=a[i];
        }
        
        int rightSum = sum;
        int leftSum = 0;
        
        for(int i=0;i<n;++i){
            // before checking current elt as pivot -> remove it from the rightsum
            rightSum-=a[i]; 
            if(leftSum==rightSum)return i;
            
            // after checking current elt as pivot -> add it to the leftSum
            leftSum+=a[i];
        }
        return -1;
    }
};