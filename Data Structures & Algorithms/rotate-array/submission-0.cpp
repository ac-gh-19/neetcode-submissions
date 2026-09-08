class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // keep rotation within array bounds
        int steps = k % nums.size(); 
        int curr = nums.size() - 1;

        vector<int> lastKElements(steps, 0);

        for (int i = steps - 1; i >= 0; --i) {
            lastKElements[i] = nums[curr--];
        }

        for (int i = curr; i >= 0; --i) {
            nums[i + steps] = nums[i];
        }

        for (int i = 0; i < steps; ++i) {
            nums[i] = lastKElements[i];
        }




    }
};