class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> billToAmount;
        for (int i = 0; i < bills.size(); ++i) {
            billToAmount[bills[i]]++;
            if (bills[i] == 10) {
                if (billToAmount[5] == 0) {
                    return false;
                } else {
                    billToAmount[5] -= 1;
                }
            } else if (bills[i] == 20) {
                if (billToAmount[10] >= 1 && billToAmount[5] >= 1) {
                    billToAmount[10] -= 1;
                    billToAmount[5] -= 1;
                } else if (billToAmount[5] >= 3) {
                    billToAmount[5] -= 3;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};