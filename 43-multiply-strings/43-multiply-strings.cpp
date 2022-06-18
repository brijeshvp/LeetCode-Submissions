class Solution {
public:
//     string add(string a,string b){
//         string ans = "";
//         int carry = 0;
//         int i = m-1, j = n-1;
//         while(i>=0 && j>=0){
//             int tmp = (a[i]-'0') + (b[j]-'0') + carry;
//             ans.push_back(tmp%10 + '0');
//             carry = tmp/10;
//             i--;
//             j--;
//         }
        
//         while(i>=0){
//             int tmp = (a[i]-'0') + carry;
//             ans.push_back(tmp%10 + '0');
//             carry = tmp/10;
//             i--;
//         }
        
//         while(j>=0){
//             int tmp = (b[j]-'0') + carry;
//             ans.push_back(tmp%10 + '0');
//             carry = tmp/10;
//             j--;
//         }
        
//         if(carry!=0)ans.push_back(carry+'0');
        
//         reverse(ans.begin(),ans.end());
//         return ans;
//     }
    
//     string multiply(string a, string b) {
//         int m = a.size();
//         int n = b.size();
        
//         int prod = 1;
//         string ans = "0";
//         for(int i=n-1;i>=0;--i){
//             long long num = b[i]-'0';
//             long long carry = 0;
//             long long tmp = 0;
//             for(int j=m-1;j>=0;--j){
//                 int mul = num*(a[j]-'0') + carry;
//                 carry = mul/10;
//                 tmp= tmp*10 + mul%10;
//             }
//             if(carry!=0)tmp = tmp*10 + carry;
            
//             string t = to_string(tmp);
//             reverse(t.begin(),t.end());
//             tmp  = stoi(t);
//             tmp*=prod;
//             prod*=10;
//             t = to_string(tmp);
//             ans = add(ans,t);
//         }
//         return ans;
//     }
    
    
    string multiply(string a, string b) {
        if(a=="0" || b=="0")return "0";
        
        int m = a.size();
        int n = b.size();
        
        vector<int> res(m+n,0);
        // reverse both strings to bring last digit at 0th index -> as per our logic
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                int digit = (a[i]-'0')*(b[j]-'0');
                res[i+j]+= digit;
                res[i+j+1]+= res[i+j]/10;
                res[i+j]%=10;
            }
        }
        
        
        for(int i=0,j=res.size()-1;i<j;++i,--j){
            swap(res[i],res[j]);
        }
        
        int beg = 0;
        while(beg<res.size() && res[beg]==0)beg++;
        
        string ans = "";
        while(beg<res.size()){
            ans.push_back(res[beg]+'0');
            beg++;
        }
        return ans;   
    }
};