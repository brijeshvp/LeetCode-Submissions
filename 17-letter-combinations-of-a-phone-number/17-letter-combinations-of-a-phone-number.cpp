class Solution {
public:
//     map<int,string> tele;
    
//     void solve(string &s,int i,int n,vector<string>&ans,string temp){
//         if(i==n){
//             ans.push_back(temp);
//             return;
//         }
        
//         string dig = tele[s[i]-'0'];
        
//         for(int x=0;x<dig.size();++x){
//             temp.push_back(dig[x]);
//             solve(s,i+1,n,ans,temp);
//             temp.pop_back();
//         }
//     }
    
//     vector<string> letterCombinations(string a) {
//         tele[2] = "abc";
//         tele[3] = "def";
//         tele[4] = "ghi";
//         tele[5] = "jkl";
//         tele[6] = "mno";
//         tele[7] = "pqrs";
//         tele[8] = "tuv";
//         tele[9] = "wxyz";
        
//         vector<string> ans;
//         if(a.size()==0)return ans;
        
//         int n = a.size();
//         solve(a,0,n,ans,"");
        
//         return ans;
//     }
    
    
    
    void solve(int i,string s,map<char,string> &mp,string &curr,vector<string> &allCombinations){
        int n = s.size();
        if(i==n){
            allCombinations.push_back(curr);
            return;    
        }

        for(int j=0;j<mp[s[i]].size();++j){
            curr.push_back(mp[s[i]][j]);
            solve(i+1,s,mp,curr,allCombinations);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string s) {
        if(s.size()==0)return {};
        map<char,string> mp;
        mp['0'] = "0";
        mp['1'] = "1";
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        vector<string> allCombinations;
        string curr;
        solve(0,s,mp,curr,allCombinations);
        return allCombinations;
    }
};