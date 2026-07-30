class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;
        string currStr = "";
        char currChar;
        for (unsigned i = 0; i < strs.size(); ++i) {
            currStr = strs.at(i);
            string currStrKey(26, 0);
            for (unsigned j = 0; j < currStr.size(); ++j) {
                currChar = currStr.at(j);
                currStrKey.at(currChar - 'a')++;
            }
            
            anagrams[currStrKey].push_back(currStr);
        }

        vector<vector<string>> sublists;
        for (const auto& pair : anagrams) {
            sublists.push_back(pair.second);
        }
        return sublists;
    }
};
