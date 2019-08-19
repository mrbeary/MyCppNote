
//思路有点像逐次逼近法
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        vector<uint32_t> vt(32, 1);
        for (int i = 1; i <= 31; ++i)
            vt[i] = vt[i - 1] * 2;
        uint32_t res = 0;
        int index = 31;
        while (n)
        {
            if (n >= vt[index])
            {
                res = res + vt[31 - index];
                n -= vt[index];
            }
            index--;
        }
        return res;
    }
};