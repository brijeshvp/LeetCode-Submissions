class Solution {
public:
    // 1 2 2 2 2 3 3 3 3
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1 = -1, candidate2 = -1;
        int votes1 = 0, votes2 = 0;
        
        for(int i : nums){
            if(i == candidate1)votes1++;
            else if(i == candidate2)votes2++;
            else if(votes1==0){
                votes1 = 1; 
                candidate1 = i;
            }
            else if(votes2==0){
                votes2 = 1; 
                candidate2 = i;
            }
            else{
                votes1--;
                votes2--;
            }
        }
        
        vector<int> ans;
        int f1 = 0, f2 = 0;
        for(int i : nums){
            if(i == candidate1)f1++;
            if(i == candidate2)f2++;
        }
        
        if(f1>nums.size()/3)ans.push_back(candidate1);
        if(f2>nums.size()/3 && candidate1!=candidate2)ans.push_back(candidate2);
        
        return ans;
    }
};