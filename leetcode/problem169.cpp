
/*
用map记录所有数字出现的次数
然后从map中找出出现次数最多的数字
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> record; //key为数字，value为数字出现的次数
        for (auto n : nums)
            record[n]++;
        map<int, int>::iterator ite;
        int tmpmax = INT_MIN;
        int res;
        for (ite = record.begin(); ite != record.end(); ite++)
        {
            if (ite->second > nums.size() / 2)
            {
                res = ite->first;
                break;
            }
        }
        return res;
    }
};