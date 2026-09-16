class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        vector<int> freqs1(26, 0);
        vector<int> freqs2(26, 0);

        for (char c : s1) {
            freqs1[c - 'a']++;
        }

        int l = 0;
        int r = 0;
        while (r < s2.size()) {
            freqs2[s2[r++] - 'a']++;

            if ((r - l) > s1.size()) {
                freqs2[s2[l++] - 'a']--;
            }
            
            if (freqs1 == freqs2) {
                return true;
            } 

        }

        return false;

    }
};
