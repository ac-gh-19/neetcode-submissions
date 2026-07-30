class Solution {
    /**
     * @param {number[]} heights
     * @return {number}
     */
    maxArea(heights) {
        // want to find best width * height
        // have two pointers move in from right / left
        // whichever pointer is lower we move forward as we want to find max possible
        let l = 0;
        let r = heights.length - 1;
        let maxHeight = 0;
        while (l < r) {
            let width = r - l;
            let lowerHeight = Math.min(heights[l], heights[r]);
            maxHeight = Math.max(maxHeight, width * lowerHeight);
            if (heights[l] < heights[r]) {
                l += 1;
            } else {
                r -= 1;
            }
        }

        return maxHeight;
    }
}
