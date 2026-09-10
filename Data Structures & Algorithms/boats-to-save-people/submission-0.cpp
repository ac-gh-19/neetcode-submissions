class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int l = 0, r = people.size() - 1;
        int numBoats = 0;
        sort(people.begin(), people.end());

        while (l < r) {
            if ((people[l] + people[r]) <= limit) {
                l++;
                r--;
            } else {
                r--;
            }
            numBoats++;
        }

        if (l > r) return numBoats;
        return ++numBoats;
    }
};