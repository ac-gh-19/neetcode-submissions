class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // [2,1,2]
        int count = 0;
        int ans = nums[0];
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == ans) {
                count++;
                continue;
            }

            if (count == 0) {
                ans = nums[i];
                count++;
            } else {
                count--;
            }
        }

        return ans;
    }
};