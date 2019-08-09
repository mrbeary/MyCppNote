

/*
思路类似于二分法

*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int mid = (left + right) / 2;   //每轮循环有3个关键值，nums[left],nums[right],nums[mid]
            if (nums[mid] > nums[right]) //如果nums[mid] > nums[right]，那么最小值位于当前的右半部分
            {
                left = mid + 1;
            }
            else
                right = mid; //否则最小值就位于左半部分
        }
        return nums[left];
    }
};