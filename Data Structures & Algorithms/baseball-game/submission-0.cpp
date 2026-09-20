class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> records;
        for (auto op : operations) {
            if (op == "+") {
                int firstNum = records.top();
                records.pop();
                int secondNum = records.top();
                records.push(firstNum);
                records.push(firstNum + secondNum);
            } else if (op == "C") {
                records.pop();
            } else if (op == "D") {
                records.push(records.top() * 2);
            } else {
                records.push(stoi(op));
            }
        }

        int sum = 0;
        while (!records.empty()) {
            sum += records.top();
            records.pop();
        }

        return sum;
    }
};