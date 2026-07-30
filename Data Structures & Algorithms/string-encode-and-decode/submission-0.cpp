class Solution {
public:

    string encode(vector<string>& strs) {
        string str = "";
        for (unsigned i = 0; i < strs.size(); ++i) {
            str += strs.at(i);
            str += char(0);
        }
        cout << str;
        return str;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        string str;
        for (unsigned i = 0; i < s.size(); ++i) {
            if (s.at(i) == char(0)) {
                decoded.push_back(str);
                str = "";
            } else {
                str += s.at(i);
            }
        }
        return decoded;
    }
};
