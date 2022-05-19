class Solution {
public:
    // NOTE: 1337 is not a prime number
    int ETF(vector<int>&b,int m){
        int n = b.size();
        int ans = 0;
        int mul = 1;
        for(int i=n-1;i>=0;--i){
            ans = (ans + (mul*b[i])%m)%m; 
            mul = (mul*10)%m;
        }
        return ans;
    }
    
    int binExp(int a,int b){
        int ans = 1;
        while(b){
            if(b&1)ans = (ans*1LL*a)%1337;
            
            a = (a*1LL*a)%1337;
            b>>=1;
        }
        return ans;
    }
    
    int superPow(int a, vector<int>& b) {
        int bdash = ETF(b,1140);
        
        return binExp(a,bdash);
    }
};