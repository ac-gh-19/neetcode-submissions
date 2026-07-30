class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> values;
        for (int i = 0; i < nums.size(); ++i) {
            values.insert(nums.at(i));
        }

        int maxSequence = 0;
        int currSequence = 0;
        for (const auto num : nums) {
            if (!values.count(num - 1)) {
                currSequence = 1;
                int nextVal = num + 1;
                while (values.count(nextVal)) {
                    currSequence++;
                    nextVal++;
                }
                if (currSequence > maxSequence) maxSequence = currSequence;
            }
        }

        return maxSequence;
    }
};
