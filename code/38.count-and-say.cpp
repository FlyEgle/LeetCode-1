/*
 * [38] Count and Say
 *
 * https://leetcode.com/problems/count-and-say
 *
 * algorithms
 * Easy (34.43%)
 * Total Accepted:    141.6K
 * Total Submissions: 411.3K
 * Testcase Example:  '1'
 *
 * The count-and-say sequence is the sequence of integers with the first five
 * terms as following:
 * 
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 
 * 
 * 
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * 
 * 
 * 
 * Given an integer n, generate the nth term of the count-and-say sequence.
 * 
 * 
 * 
 * Note: Each term of the sequence of integers will be represented as a
 * string.
 * 
 * 
 * Example 1:
 * 
 * Input: 1
 * Output: "1"
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 4
 * Output: "1211"
 * 
 * 
 */
class Solution {
public:
    string countAndSay(int n) {
        string ans = "";

        if (1 == n)
            ans = "1";
        else if (2 == n) {
            ans = "11";
        } else if (n > 1){
            int counts = 1;
            string ctx = countAndSay(n - 1);

            char tmp;
            for (int i = 1; i < ctx.size(); ++i) {
                if (ctx[i] != ctx[i - 1]) {
                    tmp = counts + '0';
                    counts = 1;
                    ans = ans + tmp + ctx[i - 1];
                } else {
                    ++counts;
                }
            }
            tmp = counts + '0';
            ans = ans + tmp + ctx[ctx.size()-1];
        }

        return ans;
    }
};
