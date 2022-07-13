class Solution {
public:
    int majorityElement(vector<int> &nums){
        int candidate = INT_MIN;
        int votes = 0;
        for(int i : nums){
            if(votes==0)candidate = i;
            
            if(candidate != i)votes--;
            else votes++;      
        }
        // return candidate;
        int ct = 0;
        for(int i : nums){
            if(i==candidate)ct++;
        }
        if(ct>nums.size()/2)return candidate;
        return -1;
    }
};