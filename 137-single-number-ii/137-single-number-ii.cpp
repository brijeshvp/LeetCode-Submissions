class Solution {
public:
    int singleNumber(vector<int>& A) {
        // Logic: store/hash bits of each number in a vector of 32 size. 
        // then iterate over the vector and if elt is not multiple of 3(t[i]%3!=0) 
        // than that ith bit will be set in the resultant number
        vector<int> t(32);////Made a array contain 32 elements.
        int n = A.size();
        for (int i = 0; i < n; ++i){
            int num = A[i];
            for(int j=0;j<32;++j){
                t[j]+= (num&1);
                num>>=1;
                if(!num)break;
            }
        }

        int res = 0, k = 3; // k = elts appearing thrice(or any number of times)
        for(int i=0;i<32;++i){
            if((t[i]%k)!=0)res|= (1<<i);
        }
        return res;
    }
};