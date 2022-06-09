class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) {
        int n = a.size();
        
        int lo = 0,hi=n-1;
        
        while(lo<hi){
            if(a[lo]+a[hi]==target){
                return {lo+1,hi+1};
            }
            else if(a[lo]+a[hi]<target){
                lo++;
            }
            else if(a[lo]+a[hi]>target){
                hi--;
            }
        }
        // this return statement will never be executed(since there is always exactly 1 solution exist (given in question))
        return {-1,-1};
    }
};