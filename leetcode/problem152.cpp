
//暴力穷举法
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (!nums.size())
            return 0;
        int res = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            int tmp = 1;
            for (int j = i; j < nums.size(); j++)
            {
                tmp = tmp * nums[j];
                res = max(tmp, res);
            }
        }
        return res;
    }
};

//方案2
/*
动态规划
参考了讨论区的思路
    这道题的关键是怎么处理负数，假如到某个点，目前最大的乘积为imax，最小
乘积为imin，那么遇到负数时，imax乘以就一定为负 
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (!nums.size())
            return 0;
        int res = INT_MIN;
        int imax = 1;
        int imin = 1;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] < 0)
                swap(imax, imin); //遇到负数时，imax和imin交换一下
            imax = max(imax * nums[i], nums[i]); //假如 imax * nums[i] > nums[i],说明从i之前的某个点连续乘到i点为为最佳，若imax * nums[i] < nums[i]，就“另起炉灶”
                                                //我们不需要知道是从哪一个点开始乘的，只需知道目前谁最大就OK了
            imin = min(imin * nums[i], nums[i]);//与上一条的思路类似
            res = max(imax, res); //取出当前的最优解
            
        }
        return res;
    }
};