class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // brute(with extra space)
        int n = nums.size();
        vector<int> temp(n,0);
        int j = 0;
        for(int i=0;i<n;++i){
            if(nums[i]!=0){
                temp[j] = nums[i]; 
                j++;
            }
        }
        nums = temp;
        // intermediate -> TC: O(N^2) and SC: O(1)
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
//         int j = 0;
//         for(int i=0;i<nums.size();++i){
//             if(nums[i]!=0){
//                 nums[j] = nums[i];
//                 j++;
//             }
//         }
        
//         for(;j<nums.size();++j){
//             nums[j] = 0;
//         }
        
        
//         // best(optimal) -> TC: O(N) and SC: O(1)
//         int j = 0;
//         for(;j<nums.size();++j){
//             if(nums[j]==0)break;
//         }
        
//         for(int i=j+1;i<nums.size();++i){
//             if(nums[i]!=0){
//                 swap(nums[i],nums[j]);
//                 j++;
//             }
//         }
    }
};