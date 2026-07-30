class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // find one string
        // iterate through chars of that string
        // compare curr char to all other strings
        // if match all -> +1
        // if not match return curr substring
        if (strs.size() == 1) return strs[0];

        string substr = "";
        string first = strs[0];
        for (int i = 0; i < first.size(); ++i) {
            for (int j = 1; j < strs.size(); ++j) {
                const string comparing_string = strs[j];
                // ensures that we're not accessing an index that doesnt exist
                if (comparing_string.size() - 1 < i) return substr;
                if (comparing_string[i] != first[i]) return substr;
            }
            substr += first[i];
        }
        return substr;
    }
};