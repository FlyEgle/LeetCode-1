/*
 * [84] Largest Rectangle in Histogram
 *
 * https://leetcode.com/problems/largest-rectangle-in-histogram
 *
 * algorithms
 * Hard (26.59%)
 * Total Accepted:    99.5K
 * Total Submissions: 369.8K
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * 
 * Given n non-negative integers representing the histogram's bar height where
 * the width of each bar is 1, find the area of largest rectangle in the
 * histogram.
 * 
 * 
 * 
 * 
 * Above is a histogram where width of each bar is 1, given height =
 * [2,1,5,6,2,3].
 * 
 * 
 * 
 * 
 * The largest rectangle is shown in the shaded area, which has area = 10
 * unit.
 * 
 * 
 * 
 * For example,
 * Given heights = [2,1,5,6,2,3],
 * return 10.
 * 
 */
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0, idx;
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        stack<int> st;

        for (int i = 0; i < heights.size(); ++i) {
            while (st.size() > 0 && heights[idx = st.top()] > heights[i]) {
                st.pop();
                res = max(res, heights[idx] * (i - st.top() - 1));
            }
            st.push(i);
        }

        heights.erase(heights.begin());
        heights.pop_back();
        return res;
    }
};
