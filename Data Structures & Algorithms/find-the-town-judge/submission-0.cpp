class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // n - 1 votes for trusted person
        // the trusted person must not trust anybody

        unordered_map<int, int> personToNumTrusts;
        unordered_set<int> peopleSeen;

        for (int i = 0; i < trust.size(); ++i) {
            peopleSeen.insert(trust[i][0]);
            personToNumTrusts[trust[i][1]]++;
        }

        for (const auto& p : personToNumTrusts) {
            if (p.second == n-1) {
                bool seen = false;
                for (const auto& person : peopleSeen) {
                    if (p.first == person) {
                        seen = true;
                        break;
                    }
                }
                if (seen) {
                    continue;
                } else {
                    return p.first;
                }
            }
        }

        return -1;
    }
};