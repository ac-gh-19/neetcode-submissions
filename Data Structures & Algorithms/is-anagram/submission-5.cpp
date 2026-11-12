class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, int> chars_seen;
        for (int i = 0; i < s.size(); ++i) {
            chars_seen[s[i]]++;
            chars_seen[t[i]]--;
        }

        for (const auto& p : chars_seen) {
            if (p.second != 0) return false;
        }

        return true;
    }
};
