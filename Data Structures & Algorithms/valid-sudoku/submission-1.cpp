class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // need to store set of rows
        // need to store set of cols
        unordered_map<int, set<char>> rows;
        unordered_map<int, set<char>> cols;
        
        // i stands for current row we're on
        for (int i = 0; i < board.size(); ++i) {
            // j iterates across digit of row / stands for curr col
            for (int j = 0; j < board.size(); ++j) {
                char curr_digit = board[i][j];
                if (curr_digit == '.') continue;
                if (rows[i].count(curr_digit)) return false;
                if (cols[j].count(curr_digit)) return false;

                rows[i].insert(curr_digit);
                cols[j].insert(curr_digit);
            }
        }

        unordered_map<int, set<char>> grids;
        // i % 3 = col grid we're on
        // j % 3 = row grid we're on;
        for (int i = 0; i < board.size(); ++i) {
            int curr_row = i / 3;
            for (int j = 0; j < board.size(); ++j) {
                int grid = (curr_row * 3) + (j / 3);
                char curr_digit = board[i][j];
                if (curr_digit == '.') continue;
                if (grids[grid].count(curr_digit)) return false;
                grids[grid].insert(curr_digit);
            }
        }

        return true;
    }
};
