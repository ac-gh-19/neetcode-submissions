class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // hashmap with value: count, iterate through and keep track, see which appear >= n/3 times
        // O(n) runtime -> O(n) memory

        // sort array, check first third, check last third, if none majority, only one majority number, can use count method in majority element I problem.
        // O(nlogn) runtime -> O(1) memory

        // NOTES (At most there will be 2 answers)
        
        // keep track of increments
        // keep track of decrements
        // if increments count greater than decrements by 1/3 that means we have atleast 1 majority
        int count1 = 0, count2 = 0;
        int num1 = -1, num2 = -1;

        for (int num : nums) {
            if (num1 == num) {
                count1++;
            } else if (num2 == num) {
                count2++;
            } else if (count1 == 0) {
                num1 = num;
                count1++;
            } else if (count2 == 0) {
                num2 = num;
                count2++;
            } else {
                count1--;
                count2--;
            }
        }

        count1 = count2 = 0;
        for (int num : nums) {
            if (num1 == num) count1++;
            if (num2 == num) count2++;
        }

        vector<int> results;
        if (count1 > (nums.size() / 3)) results.push_back(num1);
        if (count2 > (nums.size() / 3)) results.push_back(num2);

        return results;

    }
};