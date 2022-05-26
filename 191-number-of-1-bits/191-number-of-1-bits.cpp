class Solution {
public:
    int hammingWeight(uint32_t n) {
        // return __builtin_popcount(n);   // using STL
        
        // using manual implementation
        int ct_setBits = 0;
        for(int i=0;i<32;++i){
            if(n&(1<<i))ct_setBits++;
        }
        
        return ct_setBits;
    }
};