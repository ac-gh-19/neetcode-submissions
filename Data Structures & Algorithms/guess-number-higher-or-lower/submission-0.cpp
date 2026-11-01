/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n;
        int m = (l + r) / 2;
        while (true) {
            int num = guess(m);
            if (num == -1) {
                r = m - 1;
            } else if (num == 1) {
                l = r + 1;
            } else if (num == 0) {
                return m;
            }
        }

        return 0;
    }
};