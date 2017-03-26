/**
 * 题目大意：
 * 给定一组数代表线段长度(也就是后面围成的水桶的桶壁高度)，x 轴做桶底，在给定的
 * 一组线段中找两条和 x 轴一块围成一个水桶(＂凹＂型)，求最多能装多少水．
 * 注意桶壁长短不一，水深应和短板长度相同．
 * */

class Solution {
public:
    int maxArea(vector<int>& height) {
        int water = 0;
        int i = 0, j = height.size() - 1;
        int h;

        while (i < j) {
            h = min(height[i], height[j]);
            water = max(water, (j - i) * h);

            while (height[i] <= h && i < j) i++;
            while (height[j] <= h && i < j) j--;
        }

        return water;
    }
};
