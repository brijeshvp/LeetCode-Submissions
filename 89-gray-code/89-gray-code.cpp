class Solution {
public:
    // Editorial: https://www.youtube.com/watch?v=KOD2BFauQbA
vector<string> solve(int n){
    // BC
    if(n==1){
        vector<string> temp;
        temp.push_back("0");
        temp.push_back("1");
        return temp;
    }
    
    vector<string> rres = solve(n-1);
    vector<string> myres;
    for(int i=0;i<rres.size();++i){
        myres.push_back("0" + rres[i]);
    }
    for(int i=rres.size()-1;i>=0;--i){
        myres.push_back("1" + rres[i]);
    }
    return myres;
}

int toDecimal(string s){
    int n = s.size();
    int res = 0;
    int prod = 1;
    for(int i=n-1;i>=0;--i){
        res+= (s[i]-'0')*prod;
        prod*=2;
    }
    return res;
}

vector<int> grayCode(int n) {
    if(n<=0)return {};
    
    vector<string> ans = solve(n);
    vector<int> res;
    for(int i=0;i<ans.size();++i){
        res.push_back(toDecimal(ans[i]));
    }
    // for(int i=0;i<res.size();++i)cout<<res[i]<<" ";
    return res;
}
};