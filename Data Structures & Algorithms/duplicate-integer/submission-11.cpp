class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::set<int> seen_nums;
        for (int num : nums) {
            if (seen_nums.count(num)) {
                return true;
            } else {
                seen_nums.insert(num);
            }
        }
        return false;
    }
};