class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> freqToAnagrams;
        for (string s : strs) {
            vector<int> freqVec(26, 0);
            for (char c : s) {
                freqVec[c - 'a']++;
            }
            

            string freqString;
            for (int n : freqVec) {
                freqString += to_string(n) + '#';
            }
            freqToAnagrams[freqString].push_back(s);
        }

        vector<vector<string>> ans;
        for (const auto& p : freqToAnagrams) {
            ans.push_back(p.second);
        }

        return ans;


    }
};
