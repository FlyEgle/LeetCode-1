/*
 * [60] Permutation Sequence
 *
 * https://leetcode.com/problems/permutation-sequence
 *
 * algorithms
 * Medium (28.36%)
 * Total Accepted:    85.5K
 * Total Submissions: 300.7K
 * Testcase Example:  '1\n1'
 *
 * The set [1,2,3,…,n] contains a total of n! unique permutations.
 * 
 * By listing and labeling all of the permutations in order,
 * We get the following sequence (ie, for n = 3):
 * 
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * 
 * 
 * 
 * Given n and k, return the kth permutation sequence.
 * 
 * Note: Given n will be between 1 and 9 inclusive.
 */
class Solution {
public:
    string getPermutation(int n, int k) {
        string str = "";
        for (int i = 1; i <= n; ++i)
            str += to_string(i);

        vector<int> kinds(n, 1);
        for (int i = n - 3; i >= 0; --i)
            kinds[i] = kinds[i + 1] * (n - 1 - i);

        k--;

        string res = "";
        for (int i = 0; i < n; ++i) {
            int select = k / kinds[i];
            k %= kinds[i];
            res += str[select];
            str.erase(next(str.begin(), select));
        }

        return res;
    }
};
