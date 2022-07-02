// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


 // } Driver Code Ends
//User function Template for C++

#define ppi pair<int,pair<int,int>>
class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> a, int k)
    {
        priority_queue<ppi,vector<ppi>,greater<ppi>> minH;
        for(int i=0;i<a.size();++i){
            minH.push({a[i][0],{i,0}});
        }
        
        vector<int> ans;
        while(minH.size()>0){
            int mx = minH.top().first;
            int arrNo = minH.top().second.first;
            int ind = minH.top().second.second;
            minH.pop();
            
            ans.push_back(mx);
            if(ind+1<a[arrNo].size())minH.push({a[arrNo][ind+1],{arrNo,ind+1}});
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}





  // } Driver Code Ends