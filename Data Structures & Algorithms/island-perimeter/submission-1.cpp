class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        queue<pair<int,int>> toVisit;
        set<pair<int,int>> visited;
        int perimeterCount = 0;

        int rowLength = grid.size();
        int colLength = grid[0].size();

        bool found = false;
        for (int i = 0; !found && i < rowLength; ++i) {
            for (int j = 0; !found && j < colLength; ++j) {
                if (grid[i][j] == 1) {
                    toVisit.push({i,j});
                    visited.insert({i,j});
                    found = true;
                }
            }
        }

        while (!toVisit.empty()) {
            auto [i,j] = toVisit.front();
            toVisit.pop();

            if (i - 1 < 0 || grid[i-1][j] == 0) {
                perimeterCount++;
            } else if (grid[i-1][j] == 1) {
                if (!visited.contains({i-1,j})) {
                    toVisit.push({i-1,j});
                    visited.insert({i-1,j});
                }
            }

            if (i + 1 >= rowLength || grid[i+1][j] == 0) {
                perimeterCount++;
            } else if (grid[i+1][j] == 1) {
                if (!visited.contains({i+1,j})) {
                    toVisit.push({i+1, j});
                    visited.insert({i+1,j});
                }
            }

            if (j - 1 < 0 || grid[i][j - 1] == 0) {
                perimeterCount++;
            } else if (grid[i][j-1] == 1) {
                if (!visited.contains({i, j - 1})) {
                    toVisit.push({i, j - 1});
                    visited.insert({i,j-1});
                }
            }

            if (j + 1 >= colLength || grid[i][j + 1] == 0) {
                perimeterCount++;
            } else if (grid[i][j+1] == 1) {
                if (!visited.contains({i, j + 1})) {
                    toVisit.push({i, j + 1});
                    visited.insert({i,j+1});
                }
            }

        }

        return perimeterCount;
        

    }
};