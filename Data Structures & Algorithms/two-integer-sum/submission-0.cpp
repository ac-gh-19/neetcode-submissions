class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // check if the target - current elements value is in
        // elements we've seen so far
        // hashmap - store key value pairs
        unordered_map<int, int> values;
        vector<int> indices;
        for (unsigned i = 0; i < nums.size(); ++i) {
            int a = nums.at(i);
            int b = target - a;
            if (values.count(b)) {
                indices.push_back(values[b]);
                indices.push_back(i);
                return indices;
            }
            values[a] = i;
        }
    }
};
