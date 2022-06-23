class Solution {
public:
    string fractionToDecimal(int n, int d) {
        string ans = "";
        bool neg = (n<0)^(d<0) ? true: false;

        long long num = abs(1LL*n), den = abs(1LL*d);   // 1LL*n and 1LL*d is done to avoid overflow
        // bcoz if n = INT_MIN then abs of INT_MIN overflow
        long long q = num/den;
        long long r = num%den;

        if(num!=0 && neg)ans+= "-";
        ans+= to_string(q);

        if(r==0){
            return ans;
        }
        else{
            ans+= ".";
            unordered_map<int,int> mp;  // {rem,position after which,this rem repeats}
            while(r!=0){
                if(mp.count(r)){
                    ans.insert(mp[r],"(");
                    ans.push_back(')');
                    return ans;
                }
                mp[r] = ans.size();

                r*=10;
                q = r/den;
                r = r%den;
                ans+= to_string(q);
            }
        }

        return ans;
    }
};