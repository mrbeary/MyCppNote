
//利用递归
/*
缺点：慢，做了大量的重复工作
leetcode上显示运行时间为1000+ms
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        if (s.size() == 0 && p.size() == 0)
            return true;
        res = false;
        func(s, p, 0, 0);
        return res;
    }
private:
    bool res;
    void func(string &s, string &p, int sindex, int pindex)
    {
        if (res)
            return;
        
        if (sindex == s.size() && pindex == p.size())
        {
            res = true;
            return;
        }
        else if (pindex == p.size())
            return;
        else if (sindex == s.size())
        {
            if (pindex + 1 < p.size() && p[pindex + 1] == '*')
                func(s, p, sindex, pindex + 2);
            return;
        }
        
        if (pindex + 1 < p.size() && p[pindex+1] == '*') //处理 * 的情况
        { 
            func(s, p, sindex, pindex + 2);
            if (s[sindex] == p[pindex] || p[pindex] == '.')
            {
                func(s, p, sindex + 1, pindex);
                func(s, p, sindex + 1, pindex + 2);
            }
        }
        else  //处理无 * 的情况
        {
            if (s[sindex] == p[pindex] || p[pindex] == '.')
                func(s, p, sindex+1, pindex + 1);
        }
    }
};

/*
带备忘录的递归，时间比上面的版本快很多，leetcode显示的是4ms
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        if (s.size() == 0 && p.size() == 0)
            return true;
        record = vector<vector<int>>(s.size()+1, vector<int>(p.size()+1, 0));
        res = false;
        func(s, p, 0, 0);
        return res;
    }
private:
    bool res;
    vector<vector<int>> record; //利用一个二维数组记录某个点是否验证过
    void func(string &s, string &p, int sindex, int pindex)
    {
        if (res)
            return;
        
        if (record[sindex][pindex] == 1)
            return; //如果为1，说明已经验证过该点，不用继续往下了
        record[sindex][pindex] = 1;  //将该点标记为已验证
        if (sindex == s.size() && pindex == p.size())
        {
            res = true;
            return;
        }
        else if (pindex == p.size())
            return;
        else if (sindex == s.size())
        {
            if (pindex + 1 < p.size() && p[pindex + 1] == '*')
                func(s, p, sindex, pindex + 2);
            return;
        }
        
        if (pindex + 1 < p.size() && p[pindex+1] == '*')
        {
            func(s, p, sindex, pindex + 2);
            if (s[sindex] == p[pindex] || p[pindex] == '.')
            {
                func(s, p, sindex + 1, pindex);
                func(s, p, sindex + 1, pindex + 2);
            }
        }
        else
        {
            if (s[sindex] == p[pindex] || p[pindex] == '.')
                func(s, p, sindex+1, pindex + 1);
        }
    }
};