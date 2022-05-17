// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int dp[10004];
    Solution(){
        memset(dp,-1,sizeof(dp));
    }
    
    bool flag = false;
    int solve(int n,int x,int y,int z){
        if(n==0)return 0;
        if(n<0)return INT_MIN;
        if(dp[n]!=-1)return dp[n];
        
        int temp = solve(n-x,x,y,z);
        int ans1 = (temp==INT_MIN)?INT_MIN:(1+temp);
        
        temp = solve(n-y,x,y,z);
        int ans2 = (temp==INT_MIN)?INT_MIN:(1+temp);
        
        temp = solve(n-z,x,y,z);
        int ans3 = (temp==INT_MIN)?INT_MIN:(1+temp);
        
        int ans = max({ans1,ans2,ans3});
        // if(ans==INT_MIN){
        //     flag = true;
        //     return dp[n] = ;
        // }
        // if(flag)return dp[n] = 0;
        // if(ans==INT_MIN){
        //     // flag = true;
        //     return dp[n] = 0;
        // }
        return dp[n] = ans;
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        // if(n==0)return 0;
        // if(n<0)return INT_MIN;
        // if(dp[n]!=-1)return dp[n];
        
        // int temp = maximizeTheCuts(n-x,x,y,z);
        // int ans1 = (temp==INT_MIN)?INT_MIN:(temp);
        
        // temp = maximizeTheCuts(n-y,x,y,z);
        // int ans2 = (temp==INT_MIN)?INT_MIN:(temp);
        
        // temp = maximizeTheCuts(n-z,x,y,z);
        // int ans3 = (temp==INT_MIN)?INT_MIN:(temp);
        
        // int ans = max({ans1,ans2,ans3});
        // if(ans==INT_MIN){
        //     flag = true;
        //     return dp[n] = -1;
        // }
        // ans = 1 + ans;
        // if(flag)return dp[n] = 0;
        // if(ans==INT_MIN){
        //     // flag = true;
        //     return dp[n] = 0;
        // }
        
        // return dp[n] = ans;
        
        int ans =  solve(n,x,y,z);
        
        if(ans==INT_MIN)return 0;
        
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends