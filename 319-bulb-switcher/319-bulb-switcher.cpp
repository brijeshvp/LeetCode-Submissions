class Solution {
public:
    int bulbSwitch(int n) {
        int ct = 0;
        for(int i=1;i<=n;++i){
            if(sqrt(i)-floor(sqrt(i))==0)ct++;
        }
        return ct;
    }
};