class Solution {
public:
    string decodeString(string s) {
        // when we come across ]
        // pop off stack until we come across storing string [ 
        stack<char> decStack;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ']') {
                // string within the brackets
                string encoded_string = "";
                while (decStack.top() != '[') {
                    encoded_string += decStack.top();
                    decStack.pop();
                }
                // we are at opening bracket so pop off
                decStack.pop();
                reverse(encoded_string.begin(), encoded_string.end());
                // number to repeat encoded string before opening bracket
                int numRepeats = 0;
                int place = 1;

                while (!decStack.empty() && isdigit(decStack.top())) {
                    int num = decStack.top() - '0';
                    num *= place;
                    place *= 10;
                    numRepeats = numRepeats + num;
                    decStack.pop();
                }

                for (int i = 0; i < numRepeats; ++i) {
                    for (int j = 0; j < encoded_string.size(); ++j) {
                        decStack.push(encoded_string[j]);
                    }
                }
            } else {
                decStack.push(s[i]);
            }
        }

        string result = "";
        while (!decStack.empty()) {
            result += decStack.top();
            decStack.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }
};