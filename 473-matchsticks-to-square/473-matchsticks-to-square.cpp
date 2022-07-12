class Solution {
public:
    // bool solve(int ind,vector<int> &m,int parts,long long prevSum,long long s){
    //     int n = m.size();
        // if(parts==0 && prevSum==s/4)return true;
        // if(parts!=0 && ind>=n)return false;
        
        // long long sum = 0;
        // for(int i=ind;i<n;++i){
        //     sum+= m[i];
        //     if(solve(i+1,m,parts-1,sum,s)==true && sum==s/4)return true;
        // }
        // return false;
    // }
    bool solve(int ind,vector<int> &m,long long target,vector<long long> &sides){
//         int n = m.size();
//         if(ind>=n && (s1==s2 && s2==s3 && s3==s4 && s1==s/4))return true;
//         if(ind>=n)return false;
        
        
//         s1+=m[ind];
//         if(solve(ind+1,m,s,s1,s2,s3,s4))return true;
//         s1-=m[ind];
//         s2+=m[ind];
//         if(solve(ind+1,m,s,s1,s2,s3,s4))return true;
//         s2-=m[ind];
//         s3+=m[ind];
//         if(solve(ind+1,m,s,s1,s2,s3,s4))return true;
//         s3-=m[ind];
//         s4+=m[ind];
//         if(solve(ind+1,m,s,s1,s2,s3,s4))return true;
//         return false;
        
        int n = m.size();
        if(ind==n){
            if(sides[0]==target && sides[1]==target && sides[2]==target)return true;
            return false;
        }
        
        for(int i=0;i<4;++i){
            if(sides[i]+m[ind]>target)continue;
            
            sides[i]+= m[ind];
            if(solve(ind+1,m,target,sides))return true;
            sides[i]-= m[ind];
        }
        return false;
    }
    
    bool makesquare(vector<int>& m) {
        if(m.size()<4)return false;
        
        sort(m.begin(),m.end(),greater<int>());
        long long s=0;
        for(int &i : m)s+=i;
        if(s%4!=0)  return false;
        // return solve(0,m,s,0,0,0,0);
        vector<long long> sides(4,0);
        return solve(0,m,s/4,sides);
        // return solve(0,m,4,0,s,);    
    }
};