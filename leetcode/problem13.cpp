
//关键是要处理类似于“IV”这种情况
//当遇到一个字符，如果它右边的字符代表的值比它大时，就是特殊情况
class Solution {
public:
    int romanToInt(string s) {
        map<char, int> dic;
        dic['I'] = 1;
        dic['V'] = 5;
        dic['X'] = 10;
        dic['L'] = 50;
        dic['C'] = 100;
        dic['D'] = 500;
        dic['M'] = 1000;
        int res = 0;
        int i = 0;
        while (i < s.size())
        {
            char cur = s[i];
            if (i + 1 < s.size() && dic[cur] < dic[s[i+1]])
            {
                res += dic[s[i+1]] - dic[cur];
                i += 2;
            }
            else
            {
                res += dic[cur];
                i++;
            }
        }
        return res;
    }
};