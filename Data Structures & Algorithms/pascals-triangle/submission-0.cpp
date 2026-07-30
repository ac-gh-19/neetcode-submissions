class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        // leftmost and rightmost index are already set to 1
        // for idx from 2nd index -> 2nd to last index
        // idx value = previous arr[idx-1] + arr[idx]
        res.push_back({1});
        for (int i = 2; i <= numRows; ++i) {
            vector<int> newRow(i);
            newRow[0] = 1; 
            newRow[newRow.size() - 1] = 1;

            vector<int> prevRow = res[i - 2];
            for (int j = 1; j < newRow.size() - 1; ++j) {
                newRow[j] = prevRow[j-1] + prevRow[j];
            }

            res.push_back(newRow);
        }

        return res;
    
    }
};