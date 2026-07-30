class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // num : frequency mapping -> for i = 0 to k -> pop off highest freq
        // O(n) space complexity O(n^2) time complexity

        // heap to keep track of highest frequency
        // pop off k times -> O(nlogn) time complexity -> O(n) space complexity

        // is there way to reverse frequency : num mapping
        // such that we can look at highest frequency nums and pop off till k = 0;

        unordered_map<int, int> num_to_freq_map;
        for (int i = 0; i < nums.size(); ++i) {
            num_to_freq_map[nums[i]] += 1;
        }

        // size 7 -> 7 + 1 = 0 1 2 3 4 5 6 7
        vector<vector<int>> index_to_frequency(nums.size() + 1);
        for (const auto& pair : num_to_freq_map) {
            index_to_frequency[pair.second].push_back(pair.first);
        }

        vector<int> result;
        for (int i = index_to_frequency.size() - 1; i >= 0; i--) {
            if (k) {
                vector<int> nums = index_to_frequency[i];
                for (int j = 0; j < nums.size(); ++j) {
                    result.push_back(nums[j]);
                    k--;
                    if (k) {
                        continue;
                    } else {
                        break;
                    }
                }
            } else {
                break;
            }
        }

        return result;
        
    }
};
