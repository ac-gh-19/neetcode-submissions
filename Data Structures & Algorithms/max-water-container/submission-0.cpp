class Solution {
public:
    int maxArea(vector<int>& heights) {
        int bestArea = 0;

        int l = 0;
        int r = heights.size() - 1;

        while (l < r) {
            int currWidth = r - l;
            if (heights[l] < heights[r]) {
                bestArea = max(bestArea, currWidth * heights[l]);
                // left height smaller than right height so we move right
                // in chance of searching for greater left height;
                l++;
            } else if (heights[l] > heights[r]) {
                bestArea = max(bestArea, currWidth * heights[r]);
                // right height smaller, move left in chance of searching
                // greater left height;
                r--;
            } else {
                bestArea = max(bestArea, currWidth * heights[r]);
                // heights are equal so we need to check whether moving left
                // or moving right yields better results
                if (heights[l + 1] > heights[r - 1]) {
                    l++;
                } else if (heights[l+1] < heights[r - 1]) {
                    r--;
                } else {
                    l++;
                    continue;
                }
            }
        }

        return bestArea;
    }
};
