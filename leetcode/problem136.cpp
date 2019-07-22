
//利用 异或的性质： A^A = 0
// 给出的数组里面只有一个是落单的，其它都是成对出现，因此成对数字异或以后会为零，最终的结果就是落单的那个数字
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i < nums.size(); ++i)
            result = result ^ nums[i];
        return result;
    }
};