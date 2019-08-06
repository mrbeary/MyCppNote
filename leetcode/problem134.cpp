
//1.0版本
/*
主要思路：用一个数组 nums 记录每个站点的“盈利”，这里的盈利是指 该站点获得的汽油 - 消耗的汽油
然后用两个“指针”left和right模拟行走的过程，left指示起点，right指示当前走到的地方
每走一步就加上当前站点的“盈利”，如果走过的站点的盈利小于 0，那么说明不符合条件，
所以我们得继续往后找新的起点
    假如我们的起点是 left，然后走到 right位置时使得走过的点的总盈利为负，那么我们可以推断，
在left和right之间无论哪个点充当起点都不能满足条件，所以新的起点得往right的后面找

在 leetcode 讨论区上看到一个概括：
    1.如果从A点出发且不能到达B点，那么A点到B点之间任何一个点作为起点都不能到达B点
    （B点是A作为起点，第一个不能到达的点）
    2.如果总的汽油量大于总消耗，那么说明有解，否则就是无解
    （就是我所说的“总盈利”）
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> nums(gas.size(), 0);
        int total = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            nums[i] = gas[i] - cost[i];
            total += nums[i];
        } // 第一次遍历，记录每个点的盈利，顺便算一下所有点的总盈利
        if (total < 0)
            return -1; //如果所有的点的总盈利都小于0，那么无论哪个点充当起点都无法走完全程
        int left = 0;
        while (left < gas.size() && nums[left] < 0)
        {
            ++left; //从头开始，找一个盈利>=0的点充当第一个起点开始找
        }
        total = nums[left];
        int right = (left + 1) % gas.size();
        while (left < gas.size() && right != left)
        {
            total += nums[right];
            right = (right + 1) % gas.size();
            if (total < 0)
            {
                total = 0;
                if (right < left)
                    break;
                left = right;
                while (left < nums.size() && nums[left] < 0) left++;
                if (left != nums.size())
                {
                    total = nums[left];
                    right = (left + 1) % gas.size();
                }
            }
        }
        if (left == right)
            return left; //left == right 表示能走完全程
        else
            return -1;
    }
};