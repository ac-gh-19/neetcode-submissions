class Solution {
public:
    int countSeniors(vector<string>& details) {
        // 0-9 -> phone numbers
        // 10 -> gender
        // 11-12 -> age
        int res = 0;

        for (const string& person : details) {
            int first_char = person[11] - '0';
            int second_char = person[12] - '0';

            if (((first_char * 10) + second_char) > 60) res++;
        }

        return res;
    }
};