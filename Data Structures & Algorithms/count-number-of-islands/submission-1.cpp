class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        int totalLands = 0;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    visited[i][j] = 1;
                    bfs(grid, pair<int, int>{i,j}, visited);
                    totalLands += 1;
                }
            }
        }

        return totalLands;
    }

    void bfs(const vector<vector<char>>& grid, pair<int, int> cell, vector<vector<int>>& visited) {
        queue<pair<int,int>> toVisit;
        toVisit.push(cell);

        vector<pair<int, int>> dirs = {
            {0, -1},
            {0, 1},
            {1, 0},
            {-1, 0}
        };

        while (!toVisit.empty()) {
            auto [i, j] = toVisit.front();
            toVisit.pop();

            for (const auto& d : dirs) {
                int nr = i + d.first;
                int nc = j + d.second;

                if (nr < 0 || nr >= grid.size()
                    || nc < 0 || nc >= grid[0].size()
                    || grid[nr][nc] == '0' || visited[nr][nc]) {
                    continue;
                } else {
                    toVisit.push({nr, nc});
                    visited[nr][nc] = 1;
                }
            }
        }
    }
};
