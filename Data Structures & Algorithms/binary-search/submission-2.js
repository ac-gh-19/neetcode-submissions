class Solution {
    /**
     * @param {number[]} nums
     * @param {number} target
     * @return {number}
     */
    search(nums, target) {
        let l = 0;
        let r = nums.length - 1;
        while (l <= r) {
            let middle = Math.floor(l + (r - l) / 2);
            if (nums[middle] == target) return middle;
            if (nums[middle] < target) {
                l = middle + 1;
            } else {
                r = middle - 1;
            }
        }

        return -1;

    }
}
