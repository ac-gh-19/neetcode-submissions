class Solution {
public:
    int findMin(vector<int> &nums) {
        // [6,1,2,3,4,5]
        // [5,6,1,2,3,4]
        // [4,5,6,1,2,3]
        // [3,4,5,6,1,2]
        // [2,3,4,5,6,1]
        // [1,2,3,4,5,6]

        int l = 0, r = nums.size() - 1;
        int min = 1001;
        
        while (l <= r) {
            if (nums[l] < nums[r]) return nums[l];
            int m = (l + r) / 2;

            // smallest is contained within l - m
            if (nums[m] < nums[l]) {
                min = nums[m];
                r = m;
            } else { // smallest is within m + 1 - r
                min = nums[r];
                l = m + 1;
            }
        }

        return min;
        
    }
};
