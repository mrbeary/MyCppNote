

//参考了leetcode上讨论区的思路
/*
动态规划：
假如我们现在所在的字符串索引为 i，从i往前找，到达j,假如j~i组成的子字符串在wordDict里能找到，并且
同样在j之前能有字符串拆分到达j，那么把vt[i]设为true
 */
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> vt(s.size()+1,false);
        vt[0] = true;
        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (vt[j])
                {
                    string tmp = s.substr(j,i-j);
                    if (find(wordDict.begin(), wordDict.end(), tmp) != wordDict.end())
                    {
                        vt[i] = true;
                        break;
                    }
                }
            }
        }
        return vt[s.size()];
    }
};