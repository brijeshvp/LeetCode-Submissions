class Solution {
public:
    int numberOfSteps(int n) {
        int ct = 0;
        while(n){
            if(n&1){
                n--;
                ct++;
            }
            else{
                n>>=1;
                ct++;
            }
        }
        return ct;
    }
};