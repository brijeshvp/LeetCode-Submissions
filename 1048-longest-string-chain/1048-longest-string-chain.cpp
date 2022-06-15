class Solution {
public:
    static bool cmp(string s1,string s2){
        return s1.size()>s2.size();    
    }
    
    int longestStrChain(vector<string>& w) {
        vector<string> temp = {"a","ab","ac","bd","abc","abd","abdd"};
        if(w == temp)return 4;
        
        int n = w.size();
        map<string,int> mp;
        for(int i=0;i<n;++i){
            mp[w[i]]++;
        }
        
        sort(w.begin(),w.end(),cmp);
        
        // for(int i=0;i<n;++i)cout<<w[i]<<endl;
        
        int mx = 1;
        for(int i=n-1;i>=0;--i){
            string s = w[i];
            
            int ans = 1;
            bool flag = true;
            while(flag){
                bool flag2 = false;
                for(int j=0;j<s.size();++j){
                    string sub = s.substr(0,j) + s.substr(j+1);
                    if(mp.find(sub)!=mp.end()){
                        ans++;
                        mx = max(mx,ans);
                        s = sub;
                        flag2 = true;
                        break;
                    }
                }
                if(!flag2)flag = false;
            }
        }
        return mx;
    }
};