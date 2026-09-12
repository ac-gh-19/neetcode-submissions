class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> numToIndexMap;
        for (int i = 0; i < nums.size(); ++i) {
            if (numToIndexMap.count(nums[i])) {
                if (max(0, i - k) <= numToIndexMap[nums[i]]) {
                    return true;
                }
            }
            numToIndexMap[nums[i]] = i;
        }

        return false;
        
    }
};