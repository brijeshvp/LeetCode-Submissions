class Solution {
public:
    // xor based solution
    int missingNumber(vector<int>& a) {
        int n = a.size();
        
        int xo1 = 0;
        for(int i=0;i<=n;++i){
            xo1 = xo1^i;
        }
        
        int xo2 = 0;
        for(int i=0;i<n;++i){
            xo2 = xo2^a[i];
        }
        
        return xo1^xo2;
    }
};