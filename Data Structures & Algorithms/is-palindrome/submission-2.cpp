class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            if (!isalnum(s.at(i))) {
                while(!isalnum(s.at(i))) {
                    i++;
                    if (i >= j) return true;
                }
            }
            if (!isalnum(s.at(j))) {
                while(!isalnum(s.at(j))) {
                    j--;
                    if (j <= i) return true;
                }
            }

            if (tolower(s.at(i)) != tolower(s.at(j))) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
