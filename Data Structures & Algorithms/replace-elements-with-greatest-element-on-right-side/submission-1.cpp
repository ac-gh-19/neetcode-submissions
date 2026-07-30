class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int curr_max = arr[arr.size() - 1];
        vector<int> res(arr.size());

        for (int i = arr.size() - 1; i >= 0; --i) {
            if (arr[i] > curr_max) {
                res[i] = curr_max;
                curr_max = arr[i];
                continue;
            }
            res[i] = curr_max;
        }

        res[arr.size() - 1] = -1;
        return res;
    }
};