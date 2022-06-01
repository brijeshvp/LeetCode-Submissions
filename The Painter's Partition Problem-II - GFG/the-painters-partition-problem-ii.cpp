// { Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    bool isPossible(long long mid,int arr[],int n,int k){
        long long allocatedBoards = 0, allocatedPainters = 1;
        for(int i=0;i<n;++i){
            if(arr[i]>mid)return false;
            
            if(allocatedBoards + arr[i] > mid){
                allocatedPainters++;
                allocatedBoards = arr[i];
            }
            else allocatedBoards+=arr[i];
        }
        if(allocatedPainters>k)return false;
        
        return true;
    }
  
    long long minTime(int arr[], int n, int k)
    {
        long long sum = 0;
        int mx = INT_MIN;
        for(int i=0;i<n;++i){
            sum+= arr[i];
            mx = max(mx,arr[i]);
        }
        
        long long minTime = -1;
        long long lo = mx, hi = sum, mid;
        while(lo<=hi){
            mid = lo + (hi-lo)/2;
            
            if(isPossible(mid,arr,n,k)){
                minTime = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        
        return minTime;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}  // } Driver Code Ends