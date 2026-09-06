class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int l1 = 0, l2 = 0;
        int count = word1.size() + word2.size();
        string result = "";
        while (count--) {
            if (l1 < word1.size()) {
                result += word1[l1];
                l1++;
            }

            if (l2 < word2.size()) {
                result += word2[l2];
                l2++;
            }
        }

        return result;

    }
};