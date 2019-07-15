

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> first = {1};
        int index = 1;
        while (index <= rowIndex)
        {
            vector<int> tmp(index+1,1);
            for (int i = 1; i < index; i++)
            {
                tmp[i] = first[i-1] + first[i];
            }
            first = tmp;
            ++index;
        }
        return first;
    }
};