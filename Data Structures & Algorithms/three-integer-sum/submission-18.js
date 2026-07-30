class Solution {
    /**
     * @param {number[]} nums
     * @return {number[][]}
     */
    threeSum(nums) {
        let triplets = [];
        let l, r;

        nums.sort((a, b) => a - b);
        for (let i = 0; i < nums.length; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            l = i + 1;
            r = nums.length - 1;
            // [-4,-1,-1,0,1,2]
            while (l < r) {
                let sum = nums.at(i) + nums.at(l) + nums.at(r);
                if (sum == 0) {
                    triplets.push([nums.at(i), nums.at(l), nums.at(r)]);
                    while (l < r && nums.at(l) == nums.at(l + 1)) l++;
                    while (l < r && nums.at(r) == nums.at(r - 1)) r--;
                    l += 1;
                    r -= 1;
                } else if (sum > 0) {
                    r -= 1;
                } else {
                    l += 1;
                }
            }
        }

        return triplets;
    }
}