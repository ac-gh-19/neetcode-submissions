class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int chosen = nums[0];
        int count = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == chosen) {
                count++;
            } else {
                if (--count == 0) {
                    chosen = nums[i];
                    count++;
                }
            }
        }

        return chosen;
    }
};