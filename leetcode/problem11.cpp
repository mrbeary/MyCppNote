
//方法一：暴力遍历所有的可能性，找出最大值
/* 
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        for (int i = 0; i < height.size(); i++)
        {
            for (int j = i+1; j < height.size(); j++)
            {
                res = max(res,min(height[i],height[j]) * (j - i)); //当前面积是左边与右边较小的一个乘以中间的
                //距离差，然后与res比较，取较大的一个
            }
        }
        return res;
    }
};
时间复杂度应该是 O(n2)
对于leetcode上的最后一个测试用例显示超时了
*/

//方案2，类似于滑动窗口
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int l = 0, r = height.size() - 1; //先定义两个“指针” l 和 r，l指向最左边，r指向最右边
        while (l < r)
        {
            res = max(res,min(height[l],height[r])*(r-l)); //计算当前的最大值
            //主要思路：若左边的高度小于右边，则左边的指针向中间移（因为想要中间的面积变大，
            //就要让较矮的边界向中间移，希望能遇到更高的
            //若右边比较矮，就右边的指针r向中间移
            if (height[l] <= height[r])
                l++;
            else
                r--;
        }
        return res;
    }
};