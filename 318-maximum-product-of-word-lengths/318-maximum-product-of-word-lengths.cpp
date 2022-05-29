class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<string,int> mp;
        for(auto it : words){
            string st = it;
            int num = 0;
            for(auto i : st){
                num|=(1<<(i-'a'));
            } 
            mp[st] = num; 
            
            // // print binary
            // for(int i=31;i>=0;--i){
            //     cout<<(((num&(1<<i))!=0)?1:0);
            // }
            // cout<<endl;
        }
        
        int mx = 0;
        for(int i=0;i<words.size()-1;++i){
            for(int j=i+1;j<words.size();++j){
                string s = words[i];
                string t = words[j];
                
                int ss = s.size();
                int ts = t.size();
                if((mp[s]&mp[t])==0){
                    mx = max(mx,ss*ts);
                }
            }
        }
        return mx;
    }
};