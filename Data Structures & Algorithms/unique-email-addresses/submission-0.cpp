class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> existingEmails;
        for (int i = 0; i < emails.size(); ++i) {
            string currEmail = emails[i];
            string parsedEmail = "";
            int atIdx = currEmail.find('@');
            for (int i = 0; i < atIdx; ++i) {
                if (currEmail[i] == '+') {
                    break;
                } else if (currEmail[i] == '.') {
                    continue;
                } else {
                    parsedEmail += currEmail[i];
                }
            }

            parsedEmail += currEmail.substr(atIdx);
            existingEmails.insert(parsedEmail);
        }

        return existingEmails.size();
    }
};