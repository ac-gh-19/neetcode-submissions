class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix.size() - 1;

        while (l <= r) {
            int m = (l + r) / 2;
            vector<int>& currArr = matrix[m];
            if (currArr[0] > target) {
                r = m - 1;
            } else if (currArr[currArr.size() - 1] < target) {
                l = m + 1;
            } else {
                int exists = bsearch(0, currArr.size() - 1, currArr, target);
                return exists == -1 ? false : true;
            }
        }

        return false;
    }

    int bsearch(int l, int r, vector<int>& nums, int target) {
        if (l > r) return -1;

        int m = l + (r - l) / 2;
        if (nums[m] == target) {
            return m;
        } else if (nums[m] < target) {
            return bsearch(m + 1, r, nums, target);
        } else {
            return bsearch(l, m - 1, nums, target);
        }
    }
};
