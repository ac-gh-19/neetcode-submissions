class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> seen_nums;

        for (int n : nums) {
            seen_nums.insert(n);
        }
        
        int max_num = 0;
        for (const int n : seen_nums) {
            int curr_count = 0;
            if (!(seen_nums.count(n - 1))) {
                int curr_num = n;
                while (seen_nums.count(curr_num)) {
                    curr_count += 1;
                    curr_num += 1;
                };
            }
            max_num = max(max_num, curr_count);
        }
        return max_num;
    }
};
