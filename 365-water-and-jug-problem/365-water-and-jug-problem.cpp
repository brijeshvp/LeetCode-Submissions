class Solution {
public:
    bool canMeasureWater(int a, int b, int t) {
        if(a+b<t)return false;
       return (t % __gcd(a,b) == 0)?true:false;
        
    }
};