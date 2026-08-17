class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> anagrams;
        for (int i = 0; i < strs.size(); ++i) {
            int wordCount[26] = {0};
            string currWord = strs[i];
            for (int j = 0; j < currWord.size(); ++j) {
                wordCount[currWord[j] - 'a']++;
            }

            string key;
            for (int k = 0; k < 26; ++k) {
                key.push_back(wordCount[k]);
            }
            anagrams[key].push_back(currWord);
        }

        for (auto& [key, words] : anagrams) {
            result.push_back(words);
        }

        return result;
    }
};
