class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::set<int> seenNums;
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            if (seenNums.count(num)) return true;
            seenNums.insert(num);
        }

        return false;
    }
};