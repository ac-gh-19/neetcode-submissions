class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> triplets;

        sort(nums.begin(), nums.end());
        // i will be pointer to first number;
        for (unsigned i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue;

            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0) {
                    j++;
                } else if (sum > 0) {
                    k--;
                } else {
                    triplets.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j-1]) j++;
                }
            }
        }
        return triplets;
    }
};
