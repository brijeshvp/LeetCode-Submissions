class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // brute -> TC: O(N^2) and SC: O(1)
//         int ctZero = 0;
//         vector<int> ind;
        
//         for(int i=0;i<nums.size();){
//             if(nums[i]==0){
//                 ctZero++;
//                 nums.erase(nums.begin()+i);
//             }
//             else i++;
//         }
        
//         while(ctZero--){
//             nums.push_back(0);
//         }
        
        // optimal -> TC: O(N) and SC: O(1)
        int j = 0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]!=0){
                nums[j] = nums[i];
                j++;
            }
        }
        
        for(;j<nums.size();++j){
            nums[j] = 0;
        }
    }
};