class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;
        for (int i = 0; i < strs.size(); ++i) {
            string count(26, 0);
            for (const char c : strs[i]) {
                count[c - 'a']++;
            }
            res[count].push_back(strs[i]);
        }

        vector<vector<string>> result;
        for (const auto& pair : res) {
            result.push_back(pair.second);
        }

        return result;
    }
};
