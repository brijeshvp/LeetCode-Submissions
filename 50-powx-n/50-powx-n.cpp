class Solution {
public:
    double myPow(double x, int m) {
        double ans = 1;
        bool mul = true;
        long long n = m;
        if(n<0){
            mul = false;
            n = -n;
        }
        
        while(n){
            if(mul){
                if(n&1) ans*=x;
                x*=x;
            }
            else{
                if(n&1) ans/=x;
                x*=x;
            }
            n>>=1;
        }
        return ans;
    }
};