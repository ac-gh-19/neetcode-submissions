class Solution {
    /**
     * @param {number[]} nums
     * @param {number} target
     * @return {number[]}
     */
    twoSum(nums: number[], target: number): number[] {
        const numToIdx = new Map<number, number>();
        for (const [idx, num] of nums.entries()) {
            if (numToIdx.has(target - num)) {
                return [numToIdx.get(target - num)!, idx];
            } else {
                numToIdx.set(num, idx);
            }
        }

        return [];
    }
}
