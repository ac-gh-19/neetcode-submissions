class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest = 0;
        int currLength = 0;
        int l = 0;
        set<char> seenChars;

        // dvdf
        for (unsigned r = 0; r < s.size(); ++r) {
            if (!seenChars.count(s[r])) { //l = 1; r = 2; set: {v, d}; longest = 2; currLength = 1;
                currLength++;
                if (currLength > longest) {
                    longest = currLength;
                }
            } else {
                while (s[l] != s[r]) { // s[0] == s[2] -> d = d 
                    seenChars.erase(s[l]);
                    l++;
                    currLength--;
                }
                seenChars.erase(s[l]);
                l++;
            }
            seenChars.insert(s[r]);
        }




        return longest;
    }
};
