class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, m = 0, r = 0;
        for (int i = 0; i < nums.size(); ++i) {
            // [2, 1, 0]
            // [lm, r]
            // [1 , 2, 0]
            // [l, mr]
            // [0, 2, 1]
            // [, lmr]
            if (nums[i] == 0) {
                swap(nums[l], nums[i]);
                if (nums[i] == 1) {
                    swap(nums[i], nums[m]);
                }
                l++;
                m++;
                r++;
            } else if (nums[i] == 1) {
                swap(nums[m], nums[i]);
                m++;
                r++;
            } else {
                swap(nums[r], nums[i]);
                r++;
            }
        }
    }
};