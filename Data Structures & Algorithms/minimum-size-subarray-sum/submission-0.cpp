class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLength = 1000000000;
        for (int i = 0; i < nums.size(); ++i) {
            int currLength = 0;
            int sum = 0;
            for (int j = i; j < nums.size(); ++j) {
                sum += nums[j];
                currLength++;
                if (sum >= target) {
                    minLength = min(minLength, currLength);
                }
            }
        }

        return minLength == 1000000000 ? 0 : minLength;
        
    }
};