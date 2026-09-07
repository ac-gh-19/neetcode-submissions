class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> res;
        int l1 = 0, l2 = 0;
        // left pointer -> nums1 | right pointer -> nums2
        // iterate till the end of whichever array -> append smaller value to the result
        // when we reach the end we know that the other array will have values all greater already in order

        while (l1 < m && l2 < n) {
            if (nums1[l1] <= nums2[l2]) {
                res.push_back(nums1[l1]);
                l1++;
            } else {
                res.push_back(nums2[l2]);
                l2++;
            }
        }

        for (int i = l1; i < m; ++i) {
            res.push_back(nums1[i]);
        }

        for (int i = l2; i < n; ++i) {
            res.push_back(nums2[i]);
        }

        for (int i = 0; i < m + n; ++i) {
            nums1[i] = res[i];
        }

    }
};