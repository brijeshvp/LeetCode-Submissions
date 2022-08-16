class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        
        int next = mp[s[s.size()-1]];
        int num = next;
        for(int i=s.size()-2;i>=0;--i){
            int curr = mp[s[i]];
            if(curr>=next)num+=curr;
            else num-=curr;
            next = curr;
        }
        return num;
    }
};