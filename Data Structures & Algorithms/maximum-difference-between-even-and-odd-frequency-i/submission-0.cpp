class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> charFreqs;
        for (const char& c : s) {
            charFreqs[c] += 1;
        }

        int lowestEvenFreq = numeric_limits<int>::max();
        int highestOddFreq = 0;
        for (const auto& [c, freq] : charFreqs) {
            if (freq % 2 == 1) {
                highestOddFreq = max(highestOddFreq, freq);
            } else {
                lowestEvenFreq = min(lowestEvenFreq, freq);
            }
        }

        return highestOddFreq - lowestEvenFreq;
    }
};