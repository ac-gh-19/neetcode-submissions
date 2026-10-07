class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int l = 1, r = piles[piles.size() - 1];

        int minTime = r;

        while (l <= r) {
            int eatingSpeed = (l + r) / 2;

            long long time = 0;
            for (int pile : piles) {
                time += ceil(static_cast<double>(pile) / eatingSpeed);
            }

            if (time <= h) {
                minTime = eatingSpeed;
                r = eatingSpeed - 1;
            } else {
                l = eatingSpeed + 1;
            }
        }

        return minTime;

    }
};
