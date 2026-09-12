class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> chars;
        int length = 0, longestLength = 0;
        int l = 0, r = 0;
        while (r < s.size()) {
            if (chars.contains(s[r])) {
                while (chars.contains(s[r])) {
                    chars.erase(s[l++]);
                    length--;
                }
            }
            chars.insert(s[r]);
            if (++length > longestLength) {
                longestLength = length;
            }
            r++;
        }

        return longestLength;
    }
};
