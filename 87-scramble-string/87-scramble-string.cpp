class Solution {
public:
   //for storing already solved problems
    unordered_map<string,bool> dp;
    
    
    bool isScramble(string s1, string s2) {
        //base cases
        
        int n = s1.size();
        
        //if both string are not equal in size(can't be scrambled)
        if(s2.size()!=n) return false;
        
        //if both string are equal(already scrambled)
        if(s1==s2) return true;   
        
        //if code is reached to this condition then following this are sure:
        //1. size of both string is equal
        //2.  string are not equal
        //so if size is equal and they are not equal and size == 1, then obviously false
        //example 'a' and 'b' size is equal ,string are not equal
        if(n==1) return false;
        
        string key = s1+" "+s2;
        
		//check if this problem has already been solved
        // if(dp.find(key)!=dp.end()) return dp[key];
        if(dp.count(key)) return dp[key];
        
        //for every iteration there can be two condition: 
        //1.we should proceed without swapping
        //2.we should swap before looking next
        for(int i=1;i<n;i++){
            //ex of without swap: gr|eat and rg|eat
            bool withoutswap = (
                //left part of first and second string
                isScramble(s1.substr(0,i),s2.substr(0,i))  
                &&
                //right part of first and second string;
                isScramble(s1.substr(i),s2.substr(i))
            );
             
            //if without swap give us right answer then we do not need 
            //to call the recursion withswap
            if(withoutswap) return dp[key] = true;
            
            //ex of withswap: gr|eat  rge|at
			//here we compare "gr" with "at" and "eat" with "rge"
            bool withswap = (
                //left part of first and right part of second 
                isScramble(s1.substr(0,i),s2.substr(n-i)) 
                &&
                //right part of first and left part of second
                isScramble(s1.substr(i),s2.substr(0,n-i)) 
            );
              
            //if withswap give us right answer then we return true
            //otherwise the for loop do it work
            if(withswap) return dp[key] =true;
            //we are not returning false in else case 
            //because we want to check further cases with the for loop
        } 
        return dp[key] = false;  
    }
};