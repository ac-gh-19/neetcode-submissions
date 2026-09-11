class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // i - j <= k 
        // subtract maximal r index to maximal l index moving l index while < r index
        // decrement both pointers until l < 0 
        int r = nums.size() - 1;
        while (r >= 0) {
            int l = max(0, r - k);
            for (int i = l; i < r; ++i) {
                if (nums[i] == nums[r]) return true;
            }
            l--;
            r--;
        }
        return false;
        
    }
};