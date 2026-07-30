class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> res;
        set<string> seen_words;
        for (int i = 0; i < words.size(); ++i) {
            const string whole_word = words[i];
            for (int j = 0; j < words.size(); ++j) {
                if (i == j) continue;
                const string sub_word = words[j];
                if ((whole_word.find(sub_word) != string::npos) && (!seen_words.count(sub_word))) {
                    res.push_back(sub_word);
                    seen_words.insert(sub_word);
                }
            }
        }
        return res;
    }
};