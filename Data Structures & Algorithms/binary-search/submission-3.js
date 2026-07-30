class Solution {
    /**
     * @param {number[]} nums
     * @param {number} target
     * @return {number}
     */
    // [-1,0,2,4,6,8] | target = 3 | l = 2, r = 3, m = 2
    search(nums, target) {
        let l = 0;
        let r = nums.length;
        while (l <= r) {
            let middle = Math.floor((l + r) / 2);
            if (nums[middle] == target) return middle;
            if (target < nums[middle]) {
                r = middle - 1;
            } else {
                l = middle + 1;
            }
        }

        return -1;

    }
}
