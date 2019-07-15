

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        int r = 1;
        while (r <= numRows)
        {
            vector<int> tmp(r, 1);
            int left = 0, right = r - 1,index = 1;
            while (index < right)
            {
                tmp[index] = result[r-2][index - 1] + result[r-2][index];
                index++;
            }
            r++;
            result.push_back(tmp);
        }
        return result;
    }
};