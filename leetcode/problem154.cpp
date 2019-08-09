
/*
思路与problem153类似
但多了有重复元素的可能
 */
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[right])
            {
                left = mid + 1;
            }
            else if (nums[mid] < nums[right])
            {
                right = mid;
            }
            else
            {//对于nums[mid] == nums[right]的情况，无法判断最小元素在左半侧还是右半侧，因此直接right--，缩小搜索范围
                right--;
            }
        }
        return nums[left];
    }
};