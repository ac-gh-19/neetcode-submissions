class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int closestElIdx = 0;
        for (int i = 1; i < arr.size(); ++i) {
            if (abs(arr[i] - x) < abs(arr[closestElIdx] - x)) {
                closestElIdx = i;
            }
        }

        vector<int> result;
        result.push_back(arr[closestElIdx]);
        k--;
        int l = closestElIdx - 1;
        int r = closestElIdx + 1;

        while (k > 0 && l >= 0 && r < arr.size()) {
            int leftDiff = abs(arr[l] - x);
            int rightDiff = abs(arr[r] - x);
            if (leftDiff == rightDiff) {
                result.push_back(arr[l--]);
            } else if (leftDiff < rightDiff) {
                result.push_back(arr[l--]);
            } else {
                result.push_back(arr[r++]);
            }
            k--;
        }

        while (k > 0) {
            if (l < 0) {
                result.push_back(arr[r++]);
            } else {
                result.push_back(arr[l--]);
            }
            k--;
        }

        sort(result.begin(), result.end());

        return result;


    }
};