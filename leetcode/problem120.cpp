

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        result = INT_MAX;
        if (triangle.size() == 0)
            return 0;
        for (int i = 1; i < triangle.size(); i++)
        {
            for (int j = 0; j < triangle[i].size(); j++)
            {
                if (j == 0)
                    triangle[i][j] += triangle[i-1][j];
                else if (j == i)
                    triangle[i][j] += triangle[i-1][j-1];
                else
                    triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
            }
        }
        for (int i = 0; i < triangle.size(); i++)
        {
            result = min(triangle[triangle.size()-1][i],result);
        }
        return result;
    }

private:
    int result;
    
};