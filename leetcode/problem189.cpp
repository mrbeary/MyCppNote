
//O(n) 空间解法：
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        vector<int> buf = nums;
        int offset = nums.size() - k;
        for (int i = 0; i < nums.size(); i++)
        {
            int index = (i + offset) % nums.size();
            swap(nums[i], buf[index]);
        }
    }
};

//O(1) 空间解法：
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        if (nums.size() == 0 || k == 0)
            return;
        int buf = nums[0];
        int offset = nums.size() - k;
        int nextPos = 0;
        int count = 0;
        while (count < nums.size())
        {
            int start = nextPos;
            do {
                swap(nums[nextPos], buf);
                nextPos = (nextPos + k) % nums.size();
                ++count;
            } while (nextPos != start);
            swap(nums[nextPos], buf);
            nextPos++;
        }
        
    }
};