
//双层循环嵌套 + 双指针
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4)
            return {};
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int i = 0, j = 1;
        while (i < nums.size() - 3)
        {
            j = i + 1;
            while (j < nums.size() - 2) //i 和 j分别指示第一第二个数
            {
                int left = j + 1, right = nums.size() - 1;
                while (left < right) //left和right分别指示第三第四个数
                {
                    int tmp = nums[i]+nums[j]+nums[left]+nums[right];
                    if (tmp == target)
                    {
                        vector<int> tmpVt = {nums[i],nums[j],nums[left],nums[right]};
                        res.push_back(tmpVt);
                        do{
                            right--;
                        } while (right > 0 && nums[right] == nums[right +1]);
                    }
                    else if (tmp > target)
                    {
                        right--;
                    }
                    else
                    {
                        left++;
                    }
                    
                }
                j++;
                while (j < nums.size() && nums[j] == nums[j-1]) j++;
            }
            i++;
            while (i < nums.size() && i > 0 && nums[i] == nums[i-1]) i++;
        }
        return res;
    }
};