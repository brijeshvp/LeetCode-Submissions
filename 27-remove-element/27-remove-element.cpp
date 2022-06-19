class Solution {
public:
    int removeElement(vector<int>& a, int val) {
        int i = 0, j = 0;
        int n = a.size();
        if(n==0)return 0;
        
        if(a[0]==val)j++;
        while(i<n && j<n){
            if(a[j]!=val){
                a[i] = a[j];
                i++;
            }
            j++;
        }
        return i;
    }
};