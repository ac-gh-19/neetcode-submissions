class Solution {
public:
    bool isAnagram(string s, string t) {
        // char: amount seen
        unordered_map<char, int> charFreqS;
        for (int i = 0; i < s.size(); ++i) {
            charFreqS[s.at(i)] += 1;
        }

        unordered_map<char, int> charFreqT;
        for (int i = 0; i < t.size(); ++i) {
            charFreqT[t.at(i)] += 1;
        }

        if (charFreqS != charFreqT) return false;
        return true;
    }
};
