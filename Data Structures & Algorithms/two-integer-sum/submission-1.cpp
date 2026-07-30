class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seenNums;
        int firstNum, secondNum;
        for (int i = 0; i < nums.size(); ++i) {
            firstNum = nums.at(i);
            secondNum = target - firstNum;
            if (seenNums.count(secondNum)) {
                return {seenNums[secondNum], i};
            } else {
                seenNums[firstNum] = i;
            }
        }
        return {};
    }
};
