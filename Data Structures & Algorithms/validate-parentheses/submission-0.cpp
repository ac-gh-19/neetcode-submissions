class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0) return false;
        stack<char> brackets;
        for (int i = 0; i < s.size(); ++i) {
            char currEl = s.at(i);
            if (currEl == ')' || currEl == '}' || currEl == ']') {
                if (brackets.empty()) return false;
                char prevEl = brackets.top();
                brackets.pop();
                if (prevEl == '(' && currEl != ')') return false;
                if (prevEl == '{' && currEl != '}') return false;
                if (prevEl == '[' && currEl != ']') return false;
            } else {
                brackets.push(currEl);
            }
        }
        if (!brackets.empty()) return false;
        return true;
    }
};
