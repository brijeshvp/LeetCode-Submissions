class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& s) {
        int n = s.size();
        vector<unordered_set<char>> rows(n),cols(n);
        vector<vector<unordered_set<char>>> squares(n/3,vector<unordered_set<char>> (n/3));

        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(s[i][j]=='.')continue;
                if(rows[i].count(s[i][j]) || cols[j].count(s[i][j]) || squares[i/3][j/3].count(s[i][j]))return 0;

                rows[i].insert(s[i][j]);
                cols[j].insert(s[i][j]);
                squares[i/3][j/3].insert(s[i][j]);
            }
        }
        return 1;
    }
};