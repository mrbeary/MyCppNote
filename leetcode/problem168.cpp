

/*

思路与十进制转二进制类似
其实这就是十进制转“二十六进制”

*/
class Solution {
public:
    string convertToTitle(int n) {
        string s;
        while (n)
        {
            --n;
            char tmp = n % 26 + 'A';
            s = tmp + s;
            n = n / 26;
        }
        return s;
    }
};