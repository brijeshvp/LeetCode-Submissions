class Solution {
public:
    string intToRoman(int n) {
        vector<int> nums = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string> roman_nums = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

        string roman = "";
        for(int i=0;i<nums.size();++i){
            while(n>=nums[i]){
                roman+= roman_nums[i];
                n-=nums[i];
            }
        }
        return roman;
    }
};