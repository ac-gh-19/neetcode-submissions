class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int lW = 0, lA = 0;
        while (lW < word.size() && lA < abbr.size()) {
            if (abbr[lA] == '0') {
                return false;
            }

            if (isdigit(abbr[lA])) {
                int length = 0;
                while (isdigit(abbr[lA])) {
                    length = length * 10 + (abbr[lA++] - '0');

                }
                lW += length;
            } else {
                if (word[lW] == abbr[lA]) {
                    lW++;
                    lA++;
                } else {
                    return false;
                }
            }
        }

        return lW == word.size() && lA == abbr.size(); 
    }
};