class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
      unordered_set<int> seenNums;
      for (int i = 0; i < nums.size(); ++i) {
        if (seenNums.count(nums.at(i))) {
          return true;
        } else {
          seenNums.insert(nums.at(i));
        }
      }
      return false;
    }
};