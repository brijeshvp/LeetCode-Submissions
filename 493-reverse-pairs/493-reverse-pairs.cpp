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
        
        int lsz = mid - lo + 1;
        int rsz = hi - mid;
        vector<int> left(lsz,0);
        vector<int> right(rsz,0);
        for(int i=lo;i<=mid;++i)left[i-lo] = a[i];
        for(int i=mid+1;i<=hi;++i)right[i-(mid+1)] = a[i];
        
        l = 0, r = 0;
        int k = lo;
        while(l < lsz && r < rsz){
            if(left[l]<=right[r])a[k++] = left[l++];
            else a[k++] = right[r++];
        }
        while(l<lsz){
            a[k++] = left[l++];
        }
        while(r<rsz){
            a[k++] = right[r++];
        }
       // // worst case might be nlog(n) 
       //  sort(a.begin() + lo, a.begin() + hi + 1);
       //  return;
       //  //every step sort
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