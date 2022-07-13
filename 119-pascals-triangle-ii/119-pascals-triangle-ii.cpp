class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        int numerator = rowIndex;
        int denominator = 1;
        
        long long temp = 1;
        for(int i=1;i<=rowIndex+1;++i){
            ans.push_back(temp);
            temp*= numerator;
            temp/=denominator;
            numerator--;
            denominator++;
        }
        return ans;
    }
};