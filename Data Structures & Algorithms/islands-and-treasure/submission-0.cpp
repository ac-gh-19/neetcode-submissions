class Solution {
    const vector<pair<int,int>> DIRS = {
        {0,1},
        {0,-1},
        {1,0},
        {-1,0}
    };
    const int TREASURE = 0;
    const int WATER = -1;
    const int INF = INT_MAX;

public:
    void islandsAndTreasure(vector<vector<int>>& grid) {

        queue<pair<int,int>> toVisit;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == TREASURE) {
                    toVisit.push({i,j});
                }
            }
        }

        while (!toVisit.empty()) {
            auto [i, j] = toVisit.front();
            toVisit.pop();

            for (const auto& [istep,jstep] : DIRS) {
                int nr = i + istep;
                int nc = j + jstep;

                if (nr < 0 || nr >= grid.size()
                    || nc < 0 || nc >= grid[0].size()
                    || grid[nr][nc] == WATER || grid[nr][nc] != INF) {
                        continue;
                } else {
                    grid[nr][nc] = grid[i][j] + 1;
                    toVisit.push({nr,nc});
                }
            }
        }

        return;
    }
};
