class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int total = 1;
        int numZeros = 0;
        for (unsigned i = 0; i < nums.size(); ++i) {
            if (nums.at(i) == 0) { 
                numZeros++;
            } else {
                total *= nums.at(i);
            }
        };

        if (numZeros > 1) {
            vector<int> output(nums.size(), 0);
            return output;
        }

        vector<int> output;
        for (unsigned i = 0; i < nums.size(); ++i) { 
            if (numZeros == 1) {
                if (nums.at(i) != 0) {
                    output.push_back(0);
                } else {
                    output.push_back(total);
                }
            } else {
                output.push_back(total / static_cast<double>(nums.at(i)));
            }

        }

        return output;
    }
};
