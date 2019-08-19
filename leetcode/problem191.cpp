
//逐位逐位数

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n)
        {
            if (n & 0x00000001)
                res++;
            n = n >> 1;
        }
        return res;
    }
};


//改进版
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n)
        {
            res++;
            n = n & (n - 1);//关键是这一步，n-1以后，第一个1变0，前面的所有0变1
        }
        return res;
    }
};