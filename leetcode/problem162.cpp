
//二分搜索
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int mid = (left + right) / 2;
            int rnum = (mid == nums.size() - 1)? INT_MIN : nums[mid+1];
            int lnum = (mid == 0)? INT_MIN : nums[mid-1];
            if (nums[mid] > lnum && nums[mid] > rnum)
                return mid;
            if (nums[mid] >= lnum)
            {
                left = mid+1;
            }
            else
            {
                right = mid;
            }
        }
        return left;
    }
};