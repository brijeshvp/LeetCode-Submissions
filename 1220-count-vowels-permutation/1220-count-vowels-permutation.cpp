class Solution {
public:
    #define MOD 1000000007
    int solve(string &temp,int n,map<pair<int,char>,int> &dp){
        int vn = temp.size();
        if(n==0)return 1;
        if(dp.count({n,temp[vn-1]}))return dp[{n,temp[vn-1]}];
        
        long long ct = 0;
        if(temp[vn-1]=='a'){
            temp.push_back('e');
            ct = (ct + solve(temp,n-1,dp))%MOD;
        }
        else if(temp[vn-1]=='e'){
            temp.push_back('a');
            ct = (ct + solve(temp,n-1,dp))%MOD;
            temp.pop_back();
            temp.push_back('i');
            ct = (ct + solve(temp,n-1,dp))%MOD;
        }
        else if(temp[vn-1]=='i'){
            temp.push_back('a');
            ct = (ct + solve(temp,n-1,dp))%MOD;
            temp.pop_back();
            temp.push_back('e');
            ct = (ct + solve(temp,n-1,dp))%MOD;
            temp.pop_back();
            temp.push_back('o');
            ct = (ct + solve(temp,n-1,dp))%MOD;
            temp.pop_back();
            temp.push_back('u');
            ct = (ct + solve(temp,n-1,dp))%MOD;
        }
        else if(temp[vn-1]=='o'){
            temp.push_back('i');
            ct = (ct + solve(temp,n-1,dp))%MOD;
            temp.pop_back();
            temp.push_back('u');
            ct = (ct + solve(temp,n-1,dp))%MOD;
        }
        else if(temp[vn-1]=='u'){
            temp.push_back('a');
            ct = (ct + solve(temp,n-1,dp))%MOD;
        }
        
        return dp[{n,temp[vn-1]}] = ct;
    }
    
    int countVowelPermutation(int n) {
        string vowel = "aeiou";
        string temp = "";
        map<pair<int,char>,int> dp;
        int ct = 0;
        for(char ch : vowel){
            temp.push_back(ch);
            ct = (ct + solve(temp,n-1,dp))%MOD;
            temp.pop_back();
        }
        return ct;
    }
};