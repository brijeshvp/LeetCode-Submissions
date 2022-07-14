class Solution {
private:
    int count;
   
    void checkCount(vector<int>& a, int lo, int mid, int hi){
        // two pointers;
        int l = lo, r = mid + 1;
        while(l <= mid && r <= hi){
            if((long)a[l] > (long) 2 * a[r]){
                count += (mid - l + 1);
                r++;
            }else{
                l++;
            }
        }
       // worst case might be nlog(n) 
        sort(a.begin() + lo, a.begin() + hi + 1);
        return;
        
        
        
        //every step sort
    }
    void mergeSort(vector<int>& a, int lo, int hi){
        if(lo == hi) return;
        
        int mid = (lo + hi)/2;
        mergeSort(a,lo, mid);
        mergeSort(a,mid+1,hi);
        
        checkCount(a,lo,mid,hi);
        return;
        
    }
public:
    int reversePairs(vector<int>& a) {
        if(!a.size())return 0;
        count = 0;
        mergeSort(a,0,a.size()-1);
        return count;
    }
};