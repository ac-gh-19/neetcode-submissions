class Solution {
public:
    int lengthOfLastWord(string s) {
        int r = s.size() - 1;
        while (s[r] == ' ') r--;

        int length = 0;
        while (s[r] != ' ' && r >= 0) {
            length++;
            r--;
        }

        return length;
    }
};