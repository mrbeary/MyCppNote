
//带备忘录的递归
class Solution {
public:
    int rob(vector<int>& nums) {
        int res = 0;
        record = vector<int>(nums.size(), -1);
        res = func(nums.size() - 1, nums);
        return res;
    }
private:
    vector<int> record;
    int func(int index, vector<int>& nums)
    {
        if (index < 0)
        {
            return 0;
        }
        if (record[index] != -1)
            return record[index];
        record[index] =  max(nums[index] + func(index - 2, nums), func(index - 1, nums));
        /*
        nums[index] + func(index - 2, nums) 表示选择偷当前这间房子
        func(index - 1, nums) 表示不偷当前这间房子
        选择两者中较大的一个
        */
        return record[index];
    }
};

