class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0;
        int maxFreq = 0;
        int longestLength = 0;

        unordered_map<int, int> freq;

        while (r < s.size()) {
            freq[s[r]]++;
            maxFreq = max(maxFreq, freq[s[r]]);
            r++;
            int windowSize = r - l;
            while ((windowSize - maxFreq) > k) {
                freq[s[l]]--;
                maxFreq = max(maxFreq, freq[s[l++]]);
                windowSize--;
            }
            longestLength = max(longestLength, r - l);
        }

        return longestLength;
    }
};
