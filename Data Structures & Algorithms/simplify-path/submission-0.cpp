class Solution {
public:
    string simplifyPath(string path) {
        vector<string> paths;
        stringstream ss(path);
        string currPath;
        while (getline(ss, currPath, '/')) {
            paths.push_back(currPath);
        }

        vector<string> canonPath;
        for (int i = 0; i < paths.size(); ++i) {
            if (paths[i] == "." || paths[i] == "") {
                continue;
            } else if (paths[i] == "..") {
                if (!canonPath.empty()) {
                    canonPath.pop_back();
                }
            } else {
                canonPath.push_back(paths[i]);
            }
        }

        string result = "";
        for (const string& s : canonPath) {
            result += "/" + s;
        }

        return result.empty() ? "/" : result;
    }
};