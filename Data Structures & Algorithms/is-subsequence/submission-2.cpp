class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.size() > t.size()) {
            return false;
        }

        int sL = 0;

        for (int i = 0; i < t.size(); ++i) {
            if (t[i] == s[sL]) {
                sL++;
            }

            if (sL >= s.size()) return true;
        }

        return false;
        
    }
};