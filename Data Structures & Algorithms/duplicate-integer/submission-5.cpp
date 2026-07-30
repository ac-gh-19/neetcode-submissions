class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
      unordered_map<int, int> seenNums;
      for (unsigned i = 0; i < nums.size(); ++i) {
        if (seenNums.count(nums.at(i))) return true;
        seenNums[nums.at(i)] = nums.at(i);
      }
      return false;
    }
};