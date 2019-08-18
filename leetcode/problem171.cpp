


class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        int tmp = 1;
        for (int i = s.size() - 1; i >= 0; --i)
        {
            int itmp = (s[i] - 'A' + 1) * tmp;
            res += itmp;
            if (i - 1 >= 0)
                tmp *= 26;
        }
        return res;
    }
};