class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, set<int>> rows;
        unordered_map<int, set<int>> cols;
        unordered_map<int, set<int>> subBoxes;

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board.size(); ++j) {
                char value = board[i][j];

                if (value == '.') {
                    continue;
                } 

                if (rows[i].count(value)) {
                    return false;
                }
                rows[i].insert(value);

                if (cols[j].count(value)) {
                    return false;
                }
                cols[j].insert(value);

                int subBoxIndex = ((i / 3) * 3) + (j / 3);
                if (subBoxes[subBoxIndex].count(value)) {
                    return false;
                }
                subBoxes[subBoxIndex].insert(value);
                
            }
        }

        return true;
    }
};
