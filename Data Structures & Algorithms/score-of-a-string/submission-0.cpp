class Solution {
public:
    int scoreOfString(string s) {
        int sum = 0;
        for (int i = 1; i < s.size(); ++i) {
            char c = s[i];
            sum += abs(c - s[i - 1]);
        }

        return sum;
    }
};