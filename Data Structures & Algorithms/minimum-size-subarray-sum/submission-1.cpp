class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0;
        int currLength = 0, minLength = 1000000000;
        int sum = 0;

        for (int r = 0; r < nums.size(); r++) {
            sum += nums[r];
            currLength++;
            while (sum >= target) {
                minLength = min(minLength, currLength);
                sum -= nums[l++];
                currLength--;
            }
        }

        return minLength == 1000000000 ? 0 : minLength;
    }
};