
/*
带备忘录的递归
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0;
        flag = false;
        while (i + 1 < p.size())
        {
            if (p[i] == '*' && p[i + 1] == '*')
                p.erase(p.begin() + i);
            else
                i++;
        }//先将连续的 * 去掉剩下一个，例如： a*b***b变成a*b*b
        record = vector<vector<int> >(s.size() + 1, vector<int>(p.size() + 1, 0)); //记录是否访问过某个点，减少重复工作
        func(s, p, 0, 0);
        return flag;
        
    }
private:
    bool flag;
    vector<vector<int>> record;
    void func(string &s, string &p, int sindex, int pindex)
    {
        if (flag)
            return;
        if (record[sindex][pindex] == 1)
            return;
        record[sindex][pindex] = 1;
        if (sindex == s.size() && pindex == p.size())
        {
            flag = true;
            return;
        }
        else if (pindex == p.size())
            return;
        else if (sindex == s.size() && p[pindex] == '*')
            func(s, p, sindex, pindex + 1);
        else if (sindex == s.size() && p[pindex] != '*')
            return;
        
        if (isalpha(p[pindex]))
        {
            if (p[pindex] == s[sindex])
                func(s, p, sindex + 1, pindex + 1);
            else
                return;
        }
        else
        {
            if (p[pindex] == '?')
                func(s, p, sindex + 1, pindex + 1);
            else
            {
                if (sindex + 1 <= s.size())
                {
                    func(s, p, sindex + 1, pindex);
                    func(s, p, sindex + 1, pindex + 1);
                }
                func(s, p, sindex, pindex + 1);
            }
                
        }
    }
};