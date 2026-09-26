class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> results(temperatures.size(), 0);
        stack<pair<int, int>> tempAndIndex;
        for (int i = 0; i < temperatures.size(); ++i) {
            int currTemp = temperatures[i];
            // check stack for temps less than currTemp
            while (!tempAndIndex.empty() && currTemp > tempAndIndex.top().first) {
                int prevTemp = tempAndIndex.top().first;
                int prevIdx = tempAndIndex.top().second;
                results[prevIdx] = i - prevIdx;
                tempAndIndex.pop();
            }
            tempAndIndex.push({currTemp, i});
        }

        while (!tempAndIndex.empty()) {
            results[tempAndIndex.top().second] = 0;
            tempAndIndex.pop();
        }

        return results;
    }
};
