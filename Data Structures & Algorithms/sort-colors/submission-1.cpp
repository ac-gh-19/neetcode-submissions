class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0, white = 0, blue = 0;
        for (int i = 0; i < nums.size(); ++i) {
            nums[i] == 0 ? red++ : nums[i] == 1 ? white++ : blue++;
        }

        int index = 0;
        while (red--) {
            nums[index] = 0;
            index++;
        }

        while (white--) {
            nums[index] = 1;
            index++;
        }

        while (blue--) {
            nums[index] = 2;
            index++;
        }
    }
};