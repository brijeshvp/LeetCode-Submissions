// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    void merge(long long a[],long long n,long long lo,long long mid,long long hi,long long &inv,long long temp[]){
        int i = lo, j = mid+1, k = lo;
        while(i<=mid && j<=hi){
            if(a[i]<=a[j]){
                temp[k++] = a[i++];
            }
            else{
                temp[k++] = a[j++];
                inv+= (mid-i+1);
            }
        }
        
        while(i<=mid){
            temp[k++] = a[i++];
        }
        while(j<=hi){
            temp[k++] = a[j++];
        }
        
        for(int i=lo;i<=hi;++i){
            a[i] = temp[i];
        }
    }
    
    long long int ms(long long a[],long long n,long long lo,long long hi,long long temp[]){
        long long inv = 0;
        if(lo<hi){
            long long mid = lo + (hi-lo)/2;
            inv+= ms(a,n,lo,mid,temp);
            inv+= ms(a,n,mid+1,hi,temp);
            
            merge(a,n,lo,mid,hi,inv,temp);
        }
        return inv;
    }
    long long int inversionCount(long long a[], long long N)
    {
        long long temp[N];
        return ms(a,N,0,N-1,temp);
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends