class Solution {
public:
    bool isAnagram(string s, string t) {
        // key: value
        // key = char and value = count
        if (s.size() != t.size()) return false; 
        
        unordered_map<char, int> sChars;
        for (unsigned i = 0; i < s.size(); ++i) {
            sChars[s.at(i)]++;
        }

        unordered_map<char, int> tChars;
        for (unsigned i = 0; i < t.size(); ++i) {
            tChars[t.at(i)]++;
        }

        for (const auto& pair : sChars) {
            if (pair.second != tChars[pair.first]) return false;
        }
        return true;
        
    }
};
