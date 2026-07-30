class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> productsFromLeft(nums.size(), 1);
        vector<int> productsFromRight(nums.size(), 1);
        
        int product = 1;
        for (unsigned i = 0; i < nums.size(); ++i) {
            product *= nums[i];
            productsFromLeft[i] = product;
        }

        product = 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            product *= nums[i];
            productsFromRight[i] = product;
        }

        if (nums.size() == 0) {
            return nums;
        } else if (nums.size() == 1) {
            return nums;
        }

        for (unsigned i = 0; i < nums.size(); ++i) {
            if (i == 0) {
                nums[i] = productsFromRight[i+1];
            } else if (i == nums.size() - 1) {
                nums[i] = productsFromLeft[i-1];
            } else {
                nums[i] = (productsFromLeft[i-1] * productsFromRight[i+1]);
            }
        }

        return nums;
    }
};
