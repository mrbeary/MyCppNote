

class Solution {
public:
    string intToRoman(int num) {
        string res;
        vector<int> idic =    {1000, 900, 500, 400,100,  90, 50,  40,10,    9,  5,   4,  1};
        vector<string> sdic = { "M","CM", "D","CD","C","XC","L","XL","X","IX","V","IV","I"};//与上面的数组壹壹对应
        int i = 0;
        while (num && i < idic.size())
        {
            while (idic[i] > num)
                ++i;
            num -= idic[i];
            res += sdic[i];
        }
        return res;
    }
};