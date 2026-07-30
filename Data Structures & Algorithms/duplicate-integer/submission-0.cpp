class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        for (unsigned i = 0; i < nums.size(); ++i) {
            int count = 0;
            for (unsigned j = 0; j < nums.size(); ++j) {
                if (nums.at(i) == nums.at(j)) ++count;
            }
            if (count > 1) return true;
        }
        return false;
    }
};