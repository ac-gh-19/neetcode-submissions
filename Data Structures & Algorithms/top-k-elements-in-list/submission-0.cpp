class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> numFreq;
        for (int i = 0; i < nums.size(); ++i) {
            numFreq[nums.at(i)]++;
        }
        // hashmap int : freq pairing
        vector<int> results;
        while (k != 0) {
            int maxFreq = 0;
            int key;
            for (auto pair : numFreq) {
                if (pair.second > maxFreq) {
                    maxFreq = pair.second;
                    key = pair.first;
                }
            }
            numFreq.erase(key);
            results.push_back(key);
            k--;
        }
        return results;
    }
};
