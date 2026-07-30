class Solution {
    /**
     * @param {number[]} numbers
     * @param {number} target
     * @return {number[]}
     */
    twoSum(numbers, target) {
        let l = 0, r = numbers.length - 1;
        while (l < r) {
            let sum = numbers[l] + numbers[r];
            if (sum > target) {
                r -= 1;
            } else if (sum < target) {
                l += 1;
            } else {
                return [l + 1, r + 1];
            }
        }
    }

}
