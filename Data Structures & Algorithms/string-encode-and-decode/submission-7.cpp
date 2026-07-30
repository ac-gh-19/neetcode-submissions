class Solution {
public:

    string encode(vector<string>& strs) {
        string newString = "";
        for (const auto& str : strs) {
            newString += to_string(str.size()) + "#" + str;
        }
        cout << newString;
        return newString;
    }

    vector<string> decode(string s) {
        vector<string> results;
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (s.at(j) != '#') {
                j++;
            }
            int length = stoi(s.substr(i, j - i));
            i = j + 1;
            j = i + length;
            string str = s.substr(i, length);
            i = j;
            results.push_back(str);
        }
        return results;
    }
};
