
//暴力穷举
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int i = 0, j = 1;
        while (i < numbers.size())
        {
            j = i + 1;
            while (j < numbers.size())
            {
                int tmp = numbers[i] + numbers[j];
                if (tmp == target || tmp > target) //因为数组是升序排列的，如果tmp>target，后面的也不会满足，所有退出这一轮循环
                    break;
                j++;
            }
            if (j < numbers.size() && numbers[i] + numbers[j] == target)
            {
                res.push_back(i);
                res.push_back(j);
                break;
            }
            i++;
        }
        res[0]++;
        res[1]++;
        return res;
    }
    
};

//双指针法
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int i = 0, j = numbers.size() - 1;
        while (numbers[i] + numbers[j] != target)
        {
            if (numbers[i] + numbers[j] > target)
                j--;
            else
                i++;
        }
        res.push_back(i);
        res.push_back(j);
        res[0]++;
        res[1]++;
        return res;
    }
    
};