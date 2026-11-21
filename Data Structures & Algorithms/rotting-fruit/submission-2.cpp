class Solution {
    vector<pair<int,int>> DIRS = {
        {0,1},
        {0,-1},
        {-1,0},
        {1,0}
    };
    struct PairHash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // FIND ALL ROTTEN FRUITS
        // STORE POSITIONS OF NON ROTTEN FRUITS
        // PUSH ROTTEN FRUITS ONTO QUEUE
        // FOR EVERY ROTTEN FRUIT -> PUSH ADJ CELLS INTO Q
        // POP OFF ALL CELLS INTO Q UNTIL NON ROTTEN ALL FOUND

        queue<pair<int,int>> q;

        unordered_set<pair<int,int>, PairHash> nonRotten;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    nonRotten.insert({i,j});
                } else if (grid[i][j] == 2) {
                    q.push({i,j});
                }
            }
        }

        if (nonRotten.empty()) {
            return 0;
        }

        if (q.empty()) {
            return -1;
        }

        int mins = 0;
        while (!q.empty()) {
            int qsize = q.size();
            for (int i = 0; i < qsize; ++i) {
                auto [x,y] = q.front();
                q.pop();
                for (auto [xi, yi] : DIRS) {
                    int nx = x + xi;
                    int ny = y + yi;

                    // out of bounds or non fruit cell / rotten
                    if (nx < 0 || nx >= grid.size() 
                        || ny < 0 || ny >= grid[0].size()
                        || grid[nx][ny] == 0 || grid[nx][ny] == -1)
                    {
                        continue;
                    } else {
                        // fruit cell thats turned rotten
                        q.push({nx,ny});
                        nonRotten.erase({nx,ny});
                        // mark visited
                        grid[nx][ny] = 0;
                    }
                }
            }
            mins += 1;
            if (nonRotten.empty()) return mins;
        }

        if (nonRotten.empty()) return mins;
        return -1;
    }
};
