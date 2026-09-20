class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> records;
        int sum = 0;
        for (auto op : operations) {
            if (op == "+") {
                int firstNum = records.top();
                records.pop();
                int total = firstNum + records.top();
                records.push(firstNum);
                records.push(total);
                sum += total;
            } else if (op == "C") {
                sum -= records.top();
                records.pop();
            } else if (op == "D") {
                int doubled = records.top() * 2;
                sum += doubled;
                records.push(doubled);
            } else {
                sum += stoi(op);
                records.push(stoi(op));
            }
        }

        return sum;
    }
};