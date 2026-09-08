class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> seenNums; 
        int count = 0;
        int l1 = 0;

        for (const int num : nums) {
            if (seenNums.count(num)) {
                continue;
            }
            seenNums.insert(num);
            nums[l1++] = num;
            count++;
        }

        return count;
    }
};