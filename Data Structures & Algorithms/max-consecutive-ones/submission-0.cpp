class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int curr_conseq = 0;
        int max_conseq = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums.at(i) == 1) {
                curr_conseq++;
                if (curr_conseq > max_conseq) max_conseq = curr_conseq;
            } else {
                curr_conseq = 0;
            }
        }

        return max_conseq;
    }
};