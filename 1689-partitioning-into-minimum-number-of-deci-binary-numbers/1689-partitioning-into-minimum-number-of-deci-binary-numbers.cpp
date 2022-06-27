class Solution {
public:
    // just return max digit
    int minPartitions(string n) {
        return *max_element(begin(n), end(n)) - '0';
    }
};