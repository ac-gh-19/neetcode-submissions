class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> numFrequencies;
        for (int i = 0; i < nums.size(); ++i) {
            numFrequencies[nums.at(i)] += 1;
        }
        
        vector<vector<int>> arr(nums.size() + 1);
        for (const auto& pair : numFrequencies) {
            arr.at(pair.second).push_back(pair.first);
        }

        vector<int> result;
        for (unsigned i = arr.size() - 1; i >= 0; --i) {
            if (arr.at(i).size() > 0) {
                int j = arr.at(i).size();
                while (j > 0 && k > 0) {
                    result.push_back(arr.at(i).at(j - 1));
                    j -= 1;
                    k -= 1;
                    if (k == 0) return result;
                }
            }
        }

        return result;
    }
};
