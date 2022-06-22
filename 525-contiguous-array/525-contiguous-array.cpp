class Solution {
public:
    int findMaxLength(vector<int>& a) {
        int n = a.size();
    
        long long sum = 0, mx_len = 0;
        map<long long,int> mp;
        mp[0] = -1; // sum = 0 -> present at ind -1
        for(int i=0;i<n;++i){
            if(a[i]==0)sum-=1;  // add -1 to sum
            else sum+=1;
            
            // our goal is to get sum=1(it means #1s one more than #0s)
            // to get sum=1, curr sum - (curr sum) => sum = 1 
            // thus search curr sum
            if(mp.count(sum)){
                int ind = mp[sum];
                if(mx_len < (i-(ind+1)+1))mx_len = i-(ind+1)+1;
            }
            
            // if sum is already present, dont insert. bcoz we want longest length
            // (if we update, len will decrease)
            if(!mp.count(sum))mp[sum] = i;

            
        }
        return mx_len;
    }
};